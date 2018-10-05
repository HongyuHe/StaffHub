#ifndef CONNECTSQLITE_H
#define CONNECTSQLITE_H

//#include <QSqlRelationalTableModel>
//#include <QSqlDatabase>

class QTableView;

class ConnectSQLite
{
public:
    ConnectSQLite();

//    QTableView* getstaffTableView ();
    bool createConnection();
    void closeConnection();

//private:
//    QSqlRelationalTableModel *m_modle;
//    QSqlDatabase db;
//    QTableView *staffTable;
};

#endif // CONNECTSQLITE_H
