#include "dropColumn.h"
#include "ui_dropColumn.h"

DropColumn::DropColumn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropColumn)
{
    ui->setupUi(this);
}

DropColumn::~DropColumn()
{
    delete ui;
}
