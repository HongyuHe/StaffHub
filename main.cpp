#include "LogicTier.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LogicTier logicTier;

    //显示登录界面：
    logicTier.showLoginWidget();
    //连接SQLite：
    logicTier.connectSQLite();

    int endCode = app.exec();
    logicTier.disconnecSQLite();  //在主窗体关闭后，断开数据库的连接；
    return endCode;         //结束进程；
}
