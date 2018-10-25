#include "LogicTier.h"
#include "loginwidget.h"
#include "mainwidget.h"
#include "connectSQLite.h"
#include "tableAdmin.h"
#include "userinfo.h"
#include "waitWidget.h"

#include <QDebug>
#include <QTime>
#include <QCoreApplication>

LogicTier::LogicTier(QWidget *parent)
    : QMainWindow(parent)
{
    initConnectSQLite();
    initLoginWidget();
    initUserInfo();
    initMainWidget();
    initAdmin();

    connect(m_loginWidget, SIGNAL(signalLoginClicked()),
                   this, SLOT(slotLoginClicked()));
    connect(m_loginWidget, SIGNAL(signalRegisterClicked()),
                   this, SLOT(slotRegisterClicked()));
}

LogicTier::~LogicTier()
{
    delete m_loginWidget;
    delete m_userInfo;
    delete m_connectSQLite;
    delete m_mainWidget;
}

///////////////////////////////////////////// 登录界面信号接口 ////////////////////////////////////////
void LogicTier::slotLoginClicked ()     //登录按钮
{
    QString name =m_loginWidget->get_m_adminName();
    QString pswd = m_loginWidget->get_m_adminPswd();

    m_loginWidget->setUI_lineEditCheckLogin(tr("Loging......"));
    m_waitWidget->show();
    sleep(2500);
    if (m_userInfo->checkLoginInfo(name, pswd))
    {
        m_waitWidget->hide();
        m_loginWidget->setUI_lineEditCheckLogin(tr("Successful Login ! (^~^)  "));

        qDebug() << "CheckLogin:" << name << pswd;
        m_tableAdmin->set_admin_name(name);     //设置表类数据
        m_tableAdmin->set_admin_pswd(pswd);
        m_tableAdmin->printRecord();

        sleep(2000);
        m_loginWidget->hide();
        m_mainWidget->show();
    }else
    {
        m_waitWidget->hide();
        m_loginWidget->setUI_lineEditCheckLogin(tr("Your UserName or PassWord is wrong !(●︵●) "));
    }
}

void LogicTier::slotRegisterClicked ()      //注册按钮
{
    QString name =m_loginWidget->get_m_adminName();
    QString pswd = m_loginWidget->get_m_adminPswd();

    m_loginWidget->setUI_lineEditCheckLogin(tr("Registering..."));
    m_waitWidget->show();
    sleep(2500);
    if ((m_userInfo->checkRegisterInfo(name) ) &&
           (m_userInfo->addNewUser(name, pswd)) )
    {
        m_waitWidget->hide();
        m_loginWidget->setUI_lineEditCheckLogin(tr("Successful Register !(^~^) "));

        qDebug() << "CheckRegister:" << name << pswd;

        m_tableAdmin->set_admin_name(name);     //设置当前用户信息；
        m_tableAdmin->set_admin_pswd(pswd);
        m_tableAdmin->printRecord();

        sleep(2000);
        m_loginWidget->hide();
        m_mainWidget->showMaximized();
    }else
    {
        m_waitWidget->hide();
        m_loginWidget->setUI_lineEditCheckLogin(tr("This UserName has already existed! (●︵●)"));
    }
}

//////////////////////////////////////////////////登录界面//////////////////////////////////////////////
void LogicTier::initLoginWidget (void)
{
    m_loginWidget = new LoginWidget;
    m_waitWidget = new WaitWidget;
}

void LogicTier::initUserInfo (void)
{
    m_userInfo = new UserInfo;
}

void LogicTier::showLoginWidget (void)
{
    m_loginWidget->show();
}

void LogicTier::hideLoginWidget (void)
{
    m_loginWidget->hide();
}

///SQLite连接：
void LogicTier::initConnectSQLite (void)
{
    m_connectSQLite = new ConnectSQLite;
}

void LogicTier::connectSQLite (void)
{
    m_connectSQLite->createConnection();
}

void LogicTier::disconnecSQLite (void)
{
    m_connectSQLite->closeConnection();
}

//////////////////////////////////////////////////主界面//////////////////////////////////////////////
void LogicTier::initMainWidget (void)
{
    m_mainWidget = new MainWidget;
}

void LogicTier::showMainWidget (void)
{
    m_mainWidget->show();
}

//////////////////////////////////////////////////延时//////////////////////////////////////////////
void LogicTier::sleep (unsigned int msec)
{
    QTime timer = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < timer )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

//////////////////////////////////////////////////Admin表//////////////////////////////////////////////
void LogicTier::initAdmin (void)
{
    m_tableAdmin = new TableAdmin ();
}
