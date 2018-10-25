#include "waitWidget.h"
#include "ui_waitWidget.h"

WaitWidget::WaitWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WaitWidget)
{
    ui->setupUi(this);


    this->setWindowFlags(Qt::FramelessWindowHint);      //去除边框；
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
}

WaitWidget::~WaitWidget()
{
    delete ui;
}
