#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);      //去除边框；

    m_adminName.clear();
    m_adminPswd.clear();
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

QString LoginWidget::get_m_adminName () const
{
    return m_adminName;
}

QString LoginWidget::get_m_adminPswd () const
{
    return m_adminPswd;
}

//发送登录信号；
void LoginWidget::on_pushButtonLogin_clicked()
{
    m_adminName = ui->lineEditUserName->text();
    m_adminPswd = ui->lineEditPassWord->text();

    emit signalLoginClicked();
}

//发送注册信号；
void LoginWidget::on_pushButtonRegister_clicked()
{
    m_adminName = ui->lineEditUserName->text();
    m_adminPswd = ui->lineEditPassWord->text();

    emit signalRegisterClicked();
}


//UI接口：
void LoginWidget::setUI_lineEditCheckLogin (QString checkLogin)
{
    ui->lineEditCheckLogin->setText(checkLogin);
}

/////////////////////////////////////// Events //////////////////////////////////////////
/*当鼠标左键被按下时，获取主窗口左上角的位置*/
void LoginWidget::mousePressEvent(QMouseEvent *ev)      ///详见P171总结；
{
    if(ev->buttons() == Qt::LeftButton)
    {
        m_widgetMove = ev->globalPos() - this->frameGeometry().topLeft();
        ev->accept();   //鼠标事件被系统接收
    }
}

/*当鼠标左键被按下时，移动主窗口*/
void LoginWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() == Qt::LeftButton)
    {
        this->move(ev->globalPos() - m_widgetMove);
        ev->accept();
    }
}
