#include "advancedFilter.h"
#include "ui_advancedFilter.h"
#include "Database/DBagent.h"
#include "Database/tableStaff.h"
#include "Database/viewBasic.h"

#include <QString>
#include <QDebug>

AdvancedFilter::AdvancedFilter(QWidget *parent) :
    DBagent(parent),
    ui(new Ui::AdvancedFilter)
{
    ui->setupUi(this);
}

AdvancedFilter::~AdvancedFilter()
{
    delete ui;
}

///////////////////////////////////////////////////// Slots ////////////////////////////////////////////////////////
void AdvancedFilter::slotStaffTableFilter ()
{
    ui->comboBoxField->addItems(m_tableStaff->staffHeaderList);     //导入字段名称链表；
    ui->lineEditConditionValue->clear();
//    this->show();
}

////////////////////////////////////////////// 数据共有接口 ///////////////////////////////////////////////////////

int AdvancedFilter::getField () const
{
    return ui->comboBoxField->currentIndex();       //返回Combo Box中按键的index，对应类表中
    qDebug() << "Feild: " << (ui->comboBoxField->currentIndex());//属性名(XXXattrNameList)的链表；
                                                                                                            //实际是字段名链表与属性名链表的对应；
}

QString AdvancedFilter::getCompareOperator () const
{
    return ui->comboBoxCompareOperator->currentText();
    qDebug() << "Operator: " << (ui->comboBoxCompareOperator->currentText());
}

QString AdvancedFilter::getConditionValue () const
{
    return ui->lineEditConditionValue->text();
    qDebug() << "Condition: " << (ui->lineEditConditionValue->text());
}


void AdvancedFilter::on_pushButtonBeginFilter_clicked()
{
    emit signalBeginFilter();       //发送开始筛选的信号；
    this->hide();
}
