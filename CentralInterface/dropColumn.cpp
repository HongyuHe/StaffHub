#include "dropColumn.h"
#include "ui_dropColumn.h"
#include "Database/DBagent.h"
#include "Database/tableStaff.h"
#include "Database/viewBasic.h"

#include <QString>
#include <QDebug>

DropColumn::DropColumn(QWidget *parent) :
    DBagent(parent),
    ui(new Ui::DropColumn)
{
    ui->setupUi(this);
}

DropColumn::~DropColumn()
{
    delete ui;
}

////////////////////////////////////////////////////////// Slots //////////////////////////////////////////////////////////////////
void DropColumn::slotDropStaffColumn ()
{
//    this->show();
        qDebug() << "E";
    ui->comboBoxDropAttr->addItems(findOutHeaderList("Staff"));
        qDebug() << "F";
}

void DropColumn::on_pushButtonBeginDropColumn_clicked()
{
    emit signalBeginDropColumn();

    this->hide();
}
//////////////////////////////////////////////////////////// 界面数据公有接口 //////////////////////////////////////////////////////////////
int DropColumn::getDropAttrNameIndex (void)
{
    return ui->comboBoxDropAttr->currentIndex();
}

