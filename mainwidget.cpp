#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);      //去除边框；
}

MainWidget::~MainWidget()
{
    delete ui;
}

///////////////////////////////////////////////////////////// 顶栏 ////////////////////////////////////////////////////////////////
void MainWidget::on_pushButtonClose_clicked()
{
    this->close();
}

void MainWidget::on_pushButtonMax_clicked()
{
    if (this->isMaximized())
    {
        this->showNormal();
    }else
    {
        this->showMaximized();
    }
}

void MainWidget::on_pushButtonMin_clicked()
{
    this->showMinimized();
}

/////////////////////////////////////// Events //////////////////////////////////////////
/*当鼠标左键被按下时，获取主窗口左上角的位置*/
void MainWidget::mousePressEvent(QMouseEvent *ev)      ///详见P171总结；
{
    if(ev->buttons() == Qt::LeftButton)
    {
        m_widgetMove = ev->globalPos() - this->frameGeometry().topLeft();
        ev->accept();   //鼠标事件被系统接收
    }
}

/*当鼠标左键被按下时，移动主窗口*/
void MainWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() == Qt::LeftButton)
    {
        this->move(ev->globalPos() - m_widgetMove);
        ev->accept();
    }
}
