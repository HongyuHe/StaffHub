#ifndef CENTRALINTERFACE_H
#define CENTRALINTERFACE_H

//#include <QWidget>

#include"Database/DBagent.h"
#include "CentralInterface/advancedFilter.h"
#include "CentralInterface/addColumn.h"
#include "CentralInterface/dropColumn.h"

class QSqlTableModel;
class QSqlRelationalTableModel;
class QTableView;
class QBoxLayout;
//Delegate//
class DateDelegate;
class SpinDelegate;
class ComboDelegate;

namespace Ui {
class CentralInterface;
}

class CentralInterface : public DBagent /* public QWidget,*/
{
    Q_OBJECT

public:
    explicit CentralInterface(QWidget *parent = 0);
    ~CentralInterface();

signals:
    //Filter信号 (特化到表)：
    void signalStaffTableFilter ();

    //AddColumn信号：
    void signalAddColumn ();

    //DropColumn信号(特化到表)：
    void signalDropStaffColumn ();

public slots:
    ///接收开始XX的信号；
    void slotBeginFilter ();
    void slotBeginAddColumn ();
    void slotBeginDropColumn ();

private slots:
    void on_toolBoxMenu_currentChanged(int index);

    void on_toolButtonBasicView_clicked();

    void on_toolButtonWorkingView_clicked();

    void on_toolButtonStaffTable_clicked();

    void on_pushButtonSubmit_clicked();

    void on_tabWidget_currentChanged();

    void on_pushButtonRevert_clicked();

    void on_pushButtonSearch_clicked();

    void on_pushButtonFlush_clicked();

    void on_comboBoxSort_activated(int index);

    void on_pushButtonDeleteRecord_clicked();

    void on_pushButtonAddRecord_clicked();

    void on_pushButtonAdvancedFilter_clicked();

    void on_pushButtonAddColumn_clicked();

    void on_pushButtonDropColumn_clicked();

protected:
    bool hasWidget;     //QTabWidget是否显示了表：
    void UIswitch (void);   //界面组件开关；

private:
    Ui::CentralInterface *ui;

    ///*定位正在操作的对象*///
    QSqlTableModel *locateCurrentModel (void) const;
    QTableView *locateCurrentView (void) const;
    QString locateCurrentTableName (void) const;
    bool isMultipleFilter;       //多重查询的flag；

    ///*TabWidget实现*///
    void initTableWidgetTemplate (void); ///初始化所有TabWidget的表格模板页：
    QWidget *basicviewWidget;     //（基本信息视图）
    QSqlTableModel *basicviewModel;     //由于暂时无法解决QSqlRelationalTableModel表头排序的Bug;
    QTableView *basicviewView;        //故现将视图Model设置为QSqlTableModel父类；
    QBoxLayout *basicviewWidgetLayout;

    QWidget *stafftableWidget;    //（档案总览）
    QSqlRelationalTableModel *stafftableModel;
    QTableView *stafftableView;
    QBoxLayout *stafftableWidgetLayout;
    ///*封装Model的表头插入*///
    void setModelHeader ();

    ///*高级筛选*///
    AdvancedFilter *m_advancedFilter;
    void initAdvancedFilter (void);

    ///*添加属性*///
    AddColumn *m_addColumn;
    void initAddColumn (void);

    ///*删除属性*///
    DropColumn *m_dropColumn;
    void initDropColumn (void);

    ///*设置Delegate*///
    DateDelegate *m_dateDelegate;
    SpinDelegate *m_spinDelegate;
    ComboDelegate *m_comboDelegate;
    void initDelegate (void);
};

#endif // CENTRALINTERFACE_H
