#include "connectSQLite.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

ConnectSQLite::ConnectSQLite()
{

}

bool ConnectSQLite::createConnection()  ///*建立连接的固定代码*/
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
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
