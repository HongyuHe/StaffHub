#include "CentralInterface.h"
#include "ui_CentralInterface.h"
#include "Database/DBagent.h"
#include "Database/tableStaff.h"
#include "Database/viewBasic.h"
#include "CentralInterface/advancedFilter.h"
#include "CentralInterface/dropColumn.h"
#include "Delegate/datedelegate.h"
#include "Delegate/spindelegate.h"
#include "Delegate/combodelegate.h"

#include <QTabWidget>
//#include <QTableWidget>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QIcon>
#include <QTableView>
#include <QMessageBox>
#include <QAbstractTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelation>
#include <QSqlRelationalDelegate>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

CentralInterface::CentralInterface(QWidget *parent) :
    DBagent(parent),
    ui(new Ui::CentralInterface)
{
    ui->setupUi(this);

    //界面组件开关：
    hasWidget = false;
    isMultipleFilter = false;
    UIswitch();
    //初始化界面部件：
    initTableWidgetTemplate();

    //初始化界面：
    initAdvancedFilter();
    initAddColumn();
    initDropColumn();

    //初始化代理：
    initDelegate();

    //连接界面的信号和槽：
    connect(this, SIGNAL(signalStaffTableFilter()), m_advancedFilter, SLOT(slotStaffTableFilter()));
    connect(m_advancedFilter, SIGNAL(signalBeginFilter()), this, SLOT(slotBeginFilter()));

    connect(this, SIGNAL(signalAddColumn()), m_addColumn, SLOT(slotAddColumn()));
    connect(m_addColumn, SIGNAL(signalBeginAddColumn()), this, SLOT(slotBeginAddColumn()));

    connect(this, SIGNAL(signalDropStaffColumn()), m_dropColumn, SLOT(slotDropStaffColumn()));
    connect(m_dropColumn, SIGNAL(signalBeginDropColumn()), this, SLOT(slotBeginDropColumn()));
}

CentralInterface::~CentralInterface()
{
    delete ui;
}
///////////////////////////////////////////////////////////////// init ////////////////////////////////////////////////////////////
void CentralInterface::initTableWidgetTemplate (void)   //初始化所有TableView中表格模板页的组件//
{
    ///—————— 基本信息视图 ——————///
    basicviewWidget = new QWidget();
    basicviewView = new QTableView();
    basicviewWidgetLayout = new QBoxLayout(QBoxLayout::BottomToTop);  //设置布局
    basicviewView->setEditTriggers(QAbstractItemView::NoEditTriggers);   ///使视图不可编辑
    basicviewView->setSortingEnabled(true);   //设置表头点击排序（有Bug！）
    ///—————— 档案总览 ——————///
    stafftableWidget = new QWidget();
    stafftableView = new QTableView();
    stafftableWidgetLayout = new QBoxLayout(QBoxLayout::BottomToTop);  //设置布局

    stafftableView->setSortingEnabled(true);   //设置表头点击排序；
}

void CentralInterface::initAdvancedFilter ()    //初始化高级搜索界面//
{
    m_advancedFilter = new AdvancedFilter;
}

void CentralInterface::initAddColumn ()      //初始化添加列界面//
{
    m_addColumn = new AddColumn;
}

void CentralInterface::initDropColumn ()    //初始化删除列界面//
{
    m_dropColumn = new DropColumn;
}

void CentralInterface::initDelegate ()      //初始化代理//
{
    m_dateDelegate = new DateDelegate;
    m_spinDelegate = new SpinDelegate;
    m_comboDelegate = new ComboDelegate;
}

//////////////////////////////////// ToolButton按钮组切换TabWidget ////////////////////////////////
///—————— 基本信息视图 ——————///
void CentralInterface::on_toolButtonBasicView_clicked()
{
    hasWidget = true;

    basicviewModel = new QSqlTableModel(); //Model随用随申请；
    basicviewModel->setEditStrategy(QSqlTableModel::OnManualSubmit);    //设置手动提交模式；
    basicviewModel->setTable("BasicView");           //"Staff"为数据库中某一张表的名称
    basicviewModel->select();                        //执行SQL的select语句，将数据显示在QTableView中

    for (int i = 0; i < m_viewBasic->basicHeaderList.length(); i++)     //显示表头
    {
//        qDebug() << m_viewBasic->basicHeaderList.length();
        basicviewModel->setHeaderData(i, Qt::Horizontal, m_viewBasic->basicHeaderList[i]);
    }

//    basicviewModel->setRelation(10, QSqlRelation("Education", "stf_no", "edu_fullTime"));    ///设置外键；
//    basicviewModel->setRelation(11, QSqlRelation("Education", "stf_no", "edu_inService"));
//    basicviewModel->setRelation(12, QSqlRelation("Education", "stf_no", "edu_SchlandMajor"));

    basicviewView->setModel(basicviewModel);
    //设置QSqlRelationalDelegate默认代理，可将设置的外键自动在编辑时显示到combobox中；
    basicviewView->setItemDelegate(new QSqlRelationalDelegate(basicviewView));
    basicviewWidgetLayout->addWidget(basicviewView);
    basicviewWidget->setLayout(basicviewWidgetLayout);

    ui->tabWidget->insertTab(0, basicviewWidget, "基本信息表阅览"); //插入Tab页
    ui->tabWidget->setCurrentIndex(0);
}

void CentralInterface::on_toolButtonWorkingView_clicked()
{
    QWidget *tmp = new QWidget();
    ui->tabWidget->insertTab(1, tmp, "工作信息表阅览");
    ui->tabWidget->setCurrentIndex(1);
}

///—————— 档案总览 ——————///
void CentralInterface::on_toolButtonStaffTable_clicked()
{
    hasWidget = true;

    stafftableModel = new QSqlRelationalTableModel(); //Model随用随申请；
    stafftableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);    //设置手动提交模式；
    stafftableModel->setTable("Staff");           //"Staff"为数据库中某一张表的名称
    stafftableModel->select();                        //执行SQL的select语句，将数据显示在QTableView中

    for (int i = 0; i < m_tableStaff->staffHeaderList.length(); i++)        //显示表头
    {
//        qDebug() << m_tableStaff->staffHeaderList.length();
        stafftableModel->setHeaderData(i, Qt::Horizontal, m_tableStaff->staffHeaderList[i]);
    }

    stafftableModel->setRelation(10, QSqlRelation("Section", "sec_name", "sec_name"));    ///设置外键；
    stafftableModel->setRelation(11, QSqlRelation("Department", "dept_name", "dept_name"));

    stafftableView->setModel(stafftableModel);
    //设置代理//
    stafftableView->setItemDelegate(new QSqlRelationalDelegate(stafftableView));//设置QSqlRelationalDelegate默认代理，可将设置的外键自动在编辑时显示到combobox中；
    stafftableView->setItemDelegateForColumn(3, m_dateDelegate);
    stafftableView->setItemDelegateForColumn(0, m_spinDelegate);
    stafftableView->setItemDelegateForColumn(4, m_spinDelegate);
    stafftableView->setItemDelegateForColumn(5, m_comboDelegate);

    stafftableWidgetLayout->addWidget(stafftableView);
    stafftableWidget->setLayout(stafftableWidgetLayout);

    ui->tabWidget->insertTab(2, stafftableWidget, "档案编辑"); //插入Tab页
    ui->tabWidget->setCurrentIndex(2);
}

////////////////////////////////////// 切换StackedWidget /////////////////////////////////////////
void CentralInterface::on_toolBoxMenu_currentChanged(int index)
{
    switch (index) {
    case 0:
        ui->stackedWidget->setCurrentIndex(0);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        ui->stackedWidget->setCurrentIndex(1);
        break;
    case 5:
        ui->stackedWidget->setCurrentIndex(2);
        break;
    default:
        break;
    }
}

///////////////////////////////////////////// 数据操作 /////////////////////////////////////////////

void CentralInterface::on_pushButtonSubmit_clicked()    ///*提交*///
{
    QSqlTableModel *model = locateCurrentModel();

    model->database().transaction(); //开始事务操作
        if (model->submitAll())
        {
            model->database().commit(); //提交
            QMessageBox::information(this, tr("Submit Changes"), tr("Submit Successfully！！！"));
        } else {
            model->database().rollback(); //回滚
            QMessageBox::warning(this, tr("TableModel"), tr("数据库错误: %1").arg(model->lastError().text()) );
        }
}

void CentralInterface::on_pushButtonRevert_clicked()    ///*撤销*///
{
    QSqlTableModel *model = locateCurrentModel();
    model->revertAll();
}

void CentralInterface::on_pushButtonSearch_clicked()        ///*全表搜索*///
{///通过基类QSqlQueryModel指针调用派生类QSqlRelationalTableModel指针，
    ///为了使setQuery()的参数可以为QString;
    QSqlQueryModel *model = locateCurrentModel();
    QString currtableName = locateCurrentTableName();
    QString target = ui->lineEditSearch->text();
    QStringList attrList = findOutAttrList(currtableName);
    QString query = QString("Select * from %1 where").arg(currtableName);

    for (int i = 0; i < attrList.length(); i++)     ///拼接全属性where条件语句；
    {
        if (0 == i)
        {
            QString tmp = QString(" %1 = '%2' ").arg(attrList[i]).arg(target);
            query.append(tmp);
//            qDebug() << tmp;
        }else
        {
            QString tmp = QString("OR %1 = '%2' ").arg(attrList[i]).arg(target);
            query.append(tmp);
        }
//        qDebug() << attrList[i];
//        qDebug() << query;
    }
    qDebug() << query;
    model->setQuery(query);     ///QSqlTableModel下的setQuery方法是保护类型的，且参数只能是QSqlQuery类型；
}

void CentralInterface::on_pushButtonFlush_clicked()     ///*刷新全表*///
{   
    QSqlQueryModel *model = locateCurrentModel();

    if (model == basicviewModel)
    {
        on_toolButtonBasicView_clicked();

    }else if (model == stafftableModel)
    {   
        on_toolButtonStaffTable_clicked();
    }

    if (isMultipleFilter)       //若已进行筛选，则删除创建的视图；
    {////SQLite3 不支持Cascade连带删除；
        model->setQuery("Drop view FilterView");
    }
    isMultipleFilter = false;       //筛选flag置为：未筛选；

}

void CentralInterface::on_comboBoxSort_activated(int index)
{
    QSqlTableModel *model = locateCurrentModel();
    unsigned column = ui->spinBoxSortColumn->text().toInt();     //获取用户所选列好；

    column += 1;    //从1开始；
    switch (index)
    {
    case 0:
        model->setSort(column, Qt::AscendingOrder); //升序排列
        model->select();
        break;
    case 1:
        model->setSort(column, Qt::DescendingOrder);//降序排列
        model->select();
        break;
    default:
        break;
    }
}

void CentralInterface::on_pushButtonDeleteRecord_clicked()   ///*删除元组*///
{
    QSqlTableModel *model = locateCurrentModel();
    QTableView *view = locateCurrentView();
    int currRow = view->currentIndex().row();
        //获取选中的行
    model->removeRow(currRow);
    //删除该行
    int choice = QMessageBox::warning(this, tr("◤Delete Current Row◢"),tr("Ha？Are you sure"
                                                                         "you want to DELETE the current row?!"),
                         QMessageBox::Yes,QMessageBox::No);
    if(choice == QMessageBox::No)
    {
       model->revertAll(); //如果不删除，则撤销
    }else
    {
        model->submitAll(); //否则提交，在数据库中删除该行
    }
}

void CentralInterface::on_pushButtonAddRecord_clicked()      ///*添加元组*///
{
    QSqlTableModel *model = locateCurrentModel();

    int rowNum = model->rowCount(); //获得表的行数
    QString primarykey = QString (tr("PrimaryKey"));     //插入新行是必须设置主键；

    model->insertRow(rowNum); //添加一行
    model->setData(model->index(rowNum,0), primarykey);
//    model->submitAll(); //可以直接提交
}

void CentralInterface::on_pushButtonAdvancedFilter_clicked()     ///*触发高级筛选*///
{
    QSqlTableModel *model = locateCurrentModel();
    if (model == stafftableModel)
    {
        emit signalStaffTableFilter();
    }
    m_advancedFilter->show();
}

void CentralInterface::on_pushButtonAddColumn_clicked()     ///*触发AddColumn*///
{
    emit signalAddColumn();;
    m_addColumn->show();
}

void CentralInterface::on_pushButtonDropColumn_clicked()    ///*触发DropColumn*///
{
    if (locateCurrentTableName() == "Staff")
    {
        emit signalDropStaffColumn();
    }
    m_dropColumn->show();
}

/////////////////////////////////////////////////////// Slots ///////////////////////////////////////////////////

void CentralInterface::slotBeginFilter ()   ///*高级筛选（可叠加版本）*///
{///通过基类QSqlQueryModel指针调用派生类QSqlRelationalTableModel指针，为了使setQuery()的参数可以为QString;
    QSqlQueryModel *model = locateCurrentModel();
    QString currtableName = locateCurrentTableName();
    QStringList attrNameList = findOutAttrList(currtableName);      //通过DBagent获取表字段；
    QString field = attrNameList.at( m_advancedFilter->getField() );
    QString compareOperator = m_advancedFilter->getCompareOperator();
    QString conditionValue = m_advancedFilter->getConditionValue();
    QString query;
    query.clear();

    if (isMultipleFilter)
    {
        query = QString("Select * from FilterView where %1 %2 '%3'")
                .arg(field).arg(compareOperator).arg(conditionValue);

        model->setQuery(query);
        qDebug() << query;

    }else
    {       ///创建临时筛选视图FilterView，实现多重筛选：
        query = QString("Create view FilterView as select * from %1 where %2 %3 '%4'")
                .arg(currtableName).arg(field).arg(compareOperator).arg(conditionValue);
        model->setQuery(query);
        qDebug() << query;

        static_cast<QSqlTableModel *>(model)->setTable("FilterView"); ///此处很将就地把父类强行cast成子类，
        static_cast<QSqlTableModel *>(model)->select();     ///即，大指针转小指针，优越界的风险；
        setModelHeader();   //设置表头；
    }
    isMultipleFilter = true;        //flag置为：已筛选；
}

void CentralInterface::slotBeginAddColumn ()
{
    QSqlQueryModel *model = locateCurrentModel();
    QString currtableName = locateCurrentTableName();
    QString newHeaderName = m_addColumn->getNewHeaderName();
    QString newAttrName = m_addColumn->getNewAttrName();
    QString newAttrType = m_addColumn->getNewAttrType();

    qDebug() << currtableName << newHeaderName << newAttrName << newAttrType;
    //插入表头和字段链表//
    appendHeader_Attr(currtableName, newHeaderName, newAttrName);
    setModelHeader();   //重设表头；
    //插入Model//
    QString query = QString("Alter table %1 add column %2 %3")
                            .arg(currtableName).arg(newAttrName).arg(newAttrType);
    qDebug() << query;
    //询问是否添加
    int choice = QMessageBox::warning(this, tr("◤Add Column◢"),tr("Are you sure"
                                                                         "you want to ADD this Column ?!"),
                         QMessageBox::Yes,QMessageBox::No);
    if(choice == QMessageBox::No)
    {
       static_cast<QSqlTableModel *>(model)->revertAll(); //如果不添加，则撤销；
    }else
    {
        static_cast<QSqlTableModel *>(model)->submitAll(); //否则添加，在数据库中添加该属性；
        model->setQuery(query);
        on_pushButtonFlush_clicked();
    }
//    model->setQuery(query);

}

void CentralInterface::slotBeginDropColumn ()
{
    QSqlQueryModel *model = locateCurrentModel();
    QString currtableName = locateCurrentTableName();

    //删除列表中对应的属性：
    dropHeader_Attr(currtableName, m_dropColumn->getDropAttrNameIndex());

    QString query = QString("ALTER TABLE %1 RENAME TO BackUp").arg(currtableName);
    model->setQuery(query);
    qDebug() << query;

    QString query2 = QString("Create table %1 as select %2 from BackUp")
                                .arg(currtableName).arg(findOutAttrList(currtableName).join(","));
    model->setQuery(query2);
    qDebug() << query2;

    QString query3 = QString("Drop table BackUp");
//    model->setQuery(query3);
    qDebug() << query3;

    //询问是否添加
    int choice = QMessageBox::warning(this, tr("◤Drop Column◢"),tr("Are you sure"
                                                                         "you want to Drop this Column ?!"),
                         QMessageBox::Yes,QMessageBox::No);
    if(choice == QMessageBox::No)
    {
       static_cast<QSqlTableModel *>(model)->revertAll(); //如果不添加，则撤销；

    }else
    {
        static_cast<QSqlTableModel *>(model)->submitAll(); //否则添加，在数据库中添加该属性；
        model->setQuery(query3);
        on_pushButtonFlush_clicked();
    }
}

//////////////////////////////////////////////// 私有功能性方法 //////////////////////////////////////////////


QSqlTableModel *CentralInterface::locateCurrentModel(void) const   ///定位正在操作的Model///
{
    QWidget *currWidget = ui->tabWidget->currentWidget();

    if (currWidget == basicviewWidget)
    {
        return basicviewModel;

    }else if (currWidget == stafftableWidget)
    {
        return stafftableModel;
    }
    return NULL;
}

QTableView *CentralInterface::locateCurrentView (void) const     ///定位正在操作的View///
{
    QWidget *currWidget = ui->tabWidget->currentWidget();

    if (currWidget == basicviewWidget)
    {
        return basicviewView;

    }else if (currWidget == stafftableWidget)
    {
        return stafftableView;
    }
    return NULL;
}

QString CentralInterface::locateCurrentTableName (void) const   ///为QSqlQueryModel定位正在操作的表名///
{
    QWidget *currWidget = ui->tabWidget->currentWidget();

    if (currWidget == basicviewWidget)        ///由于QSqlQueryModel无法调用tableName()函数，
    {                                                                    ///故只能通过这样拙劣的方法获取当前表的名字；
        return "BasicView";

    }else if (currWidget == stafftableWidget)
    {
        return "Staff";
    }
    return "Staff";
}

void CentralInterface::setModelHeader (void)
{
    //—————————— Staff ——————————//
    for (int i = 0; i < m_tableStaff->staffHeaderList.length(); i++)        //重置表头
    {
        stafftableModel->setHeaderData(i, Qt::Horizontal, m_tableStaff->staffHeaderList[i]);
    }
qDebug() << m_tableStaff->staffHeaderList;
    stafftableModel->setRelation(10, QSqlRelation("Section", "sec_name", "sec_name"));    ///设置外键；
    stafftableModel->setRelation(11, QSqlRelation("Department", "dept_name", "dept_name"));
}

//////////////////////////////////////////////// //界面组件开关 //////////////////////////////////////////////
void CentralInterface::UIswitch (void)
{
    QSqlTableModel *model = locateCurrentModel();
    if  (!hasWidget)
    {
        ui->pushButtonAddRecord->setEnabled(false);
        ui->pushButtonDeleteRecord->setEnabled(false);
        ui->pushButtonRevert->setEnabled(false);
        ui->pushButtonSubmit->setEnabled(false);
        ui->pushButtonSearch->setEnabled(false);
        ui->pushButtonAdvancedFilter->setEnabled(false);
        ui->comboBoxSort->setEnabled(false);
        ui->spinBoxSortColumn->setEnabled(false);
        ui->pushButtonFlush->setEnabled(false);
        ui->pushButtonAddColumn->setEnabled(false);
        ui->pushButtonDropColumn->setEnabled(false);
    }else if (model == basicviewModel)
    {
        ui->pushButtonAddRecord->setEnabled(false);
        ui->pushButtonDeleteRecord->setEnabled(false);
        ui->pushButtonRevert->setEnabled(false);
        ui->pushButtonSubmit->setEnabled(false);
        ui->pushButtonSearch->setEnabled(false);
//        ui->pushButtonAdvancedFilter->setEnabled(true);
        ui->pushButtonFlush->setEnabled(true);
        ui->pushButtonAdvancedFilter->setEnabled(true);
        ui->pushButtonFlush->setEnabled(true);
//        ui->pushButtonSearch->setEnabled(true);
    }else
    {
        ui->pushButtonAddRecord->setEnabled(true);
        ui->pushButtonDeleteRecord->setEnabled(true);
        ui->pushButtonRevert->setEnabled(true);
        ui->pushButtonSubmit->setEnabled(true);
        ui->pushButtonSearch->setEnabled(true);
        ui->comboBoxSort->setEnabled(true);
        ui->spinBoxSortColumn->setEnabled(true);
        ui->pushButtonAdvancedFilter->setEnabled(true);
        ui->pushButtonFlush->setEnabled(true);
        ui->pushButtonAddColumn->setEnabled(true);
        ui->pushButtonDropColumn->setEnabled(true);
    }
}

void CentralInterface::on_tabWidget_currentChanged()    //禁止编辑视图数据（Disable PushButton）
{
    UIswitch();
}







