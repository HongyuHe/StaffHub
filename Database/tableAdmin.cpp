#include "tableAdmin.h"

#include <QDebug>

TableAdmin::TableAdmin()
{
    admin_name.clear();
    admin_pswd.clear();
    formType = "table";
}

TableAdmin::TableAdmin(QString name, QString pswd)
{
    admin_name = name;
    admin_pswd = pswd;
}

void TableAdmin::printRecord() const
{
    qDebug() << "admin_name:" << admin_name << endl;
    qDebug() << "admin_pswd" << admin_pswd << endl;
}

////////////////////////////////// get ///////////////////////////////////////
QString TableAdmin::get_admin_name () const
{
    return admin_name;
}
QString TableAdmin::get_admin_pswd () const
{
    return admin_pswd;
}

QString TableAdmin::getformType (void)
{
    return formType;
}

///////////////////////////////// set ////////////////////////////////////////
void TableAdmin::set_admin_name (QString name)
{
    admin_name = name;
}
void TableAdmin::set_admin_pswd (QString pswd)
{
    admin_pswd = pswd;
}

void TableAdmin::setrecordNumber (int num)
{
    recordNumber = num;
}
