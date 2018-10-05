#include "addColumn.h"
#include "ui_addColumn.h"
#include "Database/DBagent.h"

#include <QString>

AddColumn::AddColumn(QWidget *parent) :
    DBagent(parent),
    ui(new Ui::AddColumn)
{
    ui->setupUi(this);
}

AddColumn::~AddColumn()
{
    delete ui;
}

////////////////////////////////////////////////////////// Slots //////////////////////////////////////////////////////////////////
void AddColumn::slotAddColumn ()
{
    ui->lineEditNewAttrName->clear();;
    ui->lineEditNewHeaderName->clear();
}

//////////////////////////////////////////////////////////// 界面数据公有接口 //////////////////////////////////////////////////////////////
QString AddColumn::getNewHeaderName(void) const
{
    return ui->lineEditNewHeaderName->text();
}

QString AddColumn::getNewAttrName (void) const
{
    return ui->lineEditNewAttrName->text();
}

QString AddColumn::getNewAttrType (void) const
{
    QString attrType = ui->comboBoxNewAttrType->currentText();

    if (tr("普通文本") == attrType)
    {
        return "Varchar(500)";

    }else if (tr("大文本" )== attrType)
    {
        return "Longtext";

    }else if (tr("年-月-日") == attrType)
    {
        return "Date";

    }else if (tr("整数") == attrType)
    {
        return "int";
    }
    return NULL;
}
////////////////////////////////////////////////////////// 发送信号 ////////////////////////////////////////////////////////////////
void AddColumn::on_pushButtonBeginAddAColumn_clicked()
{
    emit signalBeginAddColumn();
    this->hide();
}
