///*此类为用户信息表，与其他表类稍有不同，其数据成员的作用主要是保存当前用户的信息*///
#ifndef TABLEADMIN_H
#define TABLEADMIN_H

#include <QString>
#include <QList>

class TableAdmin
{
public:
    TableAdmin();
    TableAdmin(QString name, QString pswd);

    void printRecord () const;

    QString get_admin_name () const;
    QString get_admin_pswd () const;

    int getrecordNumber (void);
    QString getformType (void);

    void set_admin_name (QString name);
    void set_admin_pswd (QString pswd);

    void setrecordNumber(int num);

private:
    //数据项：
    QString admin_name;
    QString admin_pswd;
    //表单记录条数：
    int recordNumber;
    //表单类型：
    QString formType;
};

typedef QList<TableAdmin> AdminRecordList;

#endif // TABLEADMIN_H
