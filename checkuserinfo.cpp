#include "checkuserinfo.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

CheckUserInfo::CheckUserInfo()
{

}

bool CheckUserInfo::checkLoginInfo (QString userName, QString userPswd)
{
    QSqlQuery query;
    QString queryString = QString("select * from Admin");

    if(query.exec(queryString))     //调用 query.exec() 执行SQL命令，执行结果存储在缓存区内；
    {
        int admin_name_idx = query.record().indexOf("admin_name");  //query.record() 提取所有缓存区的数据；
        int admin_pswd_idx = query.record().indexOf("admin_pswd");  //通过indexOf() 获取每条元组的每个属性(域名)索引；

        while(query.next())     //query.next() 自动获取下一条元组(记录)，直到 query points指向最后一条元组
        {                               //之后时，返回false；
            QString name = query.value(admin_name_idx).toString();    //根据每条元组属性索引的位置，提取其属性值；
            QString pswd = query.value(admin_pswd_idx).toString();

            if ((userName == name) && (userPswd == pswd))
            {
                return true;
            }
        }
    }else
    {
        qDebug() << "SQL Erro: Fail to select * from Admin ";
    }
    return false;
}

bool CheckUserInfo::checkRegisterInfo (QString userName)
{
    QSqlQuery query;
    QString queryString = QString("select * from Admin");

    if(query.exec(queryString))     //调用 query.exec() 执行SQL命令，执行结果存储在缓存区内；
    {
        int admin_name_idx = query.record().indexOf("admin_name");  //query.record() 提取所有缓存区的数据；
        int admin_pswd_idx = query.record().indexOf("admin_pswd");  //通过indexOf() 获取每条元组的每个属性(域名)索引；

        while(query.next())     //query.next() 自动获取下一条元组(记录)，直到 query points指向最后一条元组
        {                               //之后时，返回false；
            QString name = query.value(admin_name_idx).toString();    //根据每条元组属性索引的位置，提取其属性值；
            QString pswd = query.value(admin_pswd_idx).toString();

            if (userName == name)
            {
                return false;
            }
        }
    }else
    {
        qDebug() << "SQL Erro: Fail to select * from Admin ";
    }
    return true;
}

//添加新用户：
bool CheckUserInfo::addNewUser (QString UserName, QString UserPswd)
{
    QSqlQuery query;
    QString insert = QString("insert into Admin values ('%1' , '%2')")
                                .arg(UserName).arg(UserPswd);
    if (!query.exec(insert))
    {
        qDebug() << insert << endl;
        qDebug() << "SQL Erro: Fail to insert into Admin！";
        return false;
    }else
    {
        qDebug() << insert << endl;
        qDebug() << "Insert Successfully！";
        return true;
    }
}
