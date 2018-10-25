#ifndef CONNECTSQLITE_H
#define CONNECTSQLITE_H


class ConnectSQLite
{
public:
    ConnectSQLite();

    bool createConnection();
    void closeConnection();
};

#endif // CONNECTSQLITE_H
