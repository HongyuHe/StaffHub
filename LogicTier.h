#ifndef LOGICTIER_H
#define LOGICTIER_H

#include <QMainWindow>

class LoginWidget;
class MainWidget;
class ConnectSQLite;
class UserInfo;
class TableAdmin;
class WaitWidget;

class LogicTier : public QMainWindow
{
    Q_OBJECT

public slots:
    //登录界面信号接口
    void slotLoginClicked ();
    void slotRegisterClicked ();

public:
    LogicTier(QWidget *parent = 0);
    ~LogicTier();

    ///登录界面：
    LoginWidget *m_loginWidget;
    UserInfo *m_userInfo;   //检查登录；
    ConnectSQLite *m_connectSQLite;
    WaitWidget *m_waitWidget;

    void initLoginWidget (void);
    void initUserInfo (void);

     void showLoginWidget(void);
     void hideLoginWidget (void);

    ///初始化SQLite连接：
   void initConnectSQLite(void);

   void connectSQLite (void);
   void disconnecSQLite (void);

   ///主界面：
   MainWidget *m_mainWidget;

   void initMainWidget (void);

   void showMainWidget (void);

    ///延时：
    void sleep (unsigned int msec);

    ///Admin表：
    TableAdmin *m_tableAdmin;
    void initAdmin (void);
};

#endif // LOGICTIER_H
