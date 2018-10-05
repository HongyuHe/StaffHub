#include "connectSQLite.h"

#include <QSqlError>
#include <QDebug>
#include <QTableView>
#include <QSqlDatabase>

ConnectSQLite::ConnectSQLite()
{
}

bool ConnectSQLite::createConnection()  ///*建立连接的固定代码*/
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("HRIS.db");
    if(!db.open()){
        qCritical("Can't open database: %s(%s)",
                  db.lastError().text().toLocal8Bit().data(),
                  qt_error_string().toLocal8Bit().data());

        return false;
    }
    return true;
}

void ConnectSQLite::closeConnection()
{
    QSqlDatabase::database().close();
}

//QTableView* ConnectSQLite::getstaffTableView ()
//{
//   return staffTable;
//}
