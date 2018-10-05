#include "DBagent.h"
#include "tableAdmin.h"
#include "tableStaff.h"
#include "viewBasic.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

DBagent::DBagent(QWidget *parent)
    : QWidget(parent)
{
    //初始化表和视图：
    initTableStaff();
    initViewBasic();
}

DBagent::~DBagent()
{

}
////////////////////////////////////////////////////// 表和视图初始化 ///////////////////////////////////////////////////////////
void DBagent::initTableStaff (void)
{
    m_tableStaff = new TableStaff;
}

void  DBagent::initViewBasic (void)
{
    m_viewBasic = new ViewBasic;
}

////////////////////////////////////////////////////// FindOut ///////////////////////////////////////////////////////////
QStringList DBagent::findOutAttrList (QString tableName) const
{
    if (tableName == "BasicView")
    {
        return m_viewBasic->basicAttrNameList;
    }else if (tableName == "Staff")
    {
        return m_tableStaff->staffAttrNameList;
    }
    return m_tableStaff->staffAttrNameList;
}

QStringList DBagent::findOutHeaderList(QString tableName) const
{
    if (tableName == "BasicView")
    {
        return m_viewBasic->basicHeaderList;
    }else if (tableName == "Staff")
    {
        return m_tableStaff->staffHeaderList;
    }
    return m_tableStaff->staffHeaderList;
}

////////////////////////////////////////////////////// 操作链表 ///////////////////////////////////////////////////////////
void DBagent::appendHeader_Attr (QString tableName, QString header, QString attr)
{
    if (tableName == "Staff")
    {
        m_tableStaff->staffHeaderList.append(header);
        m_tableStaff->staffAttrNameList.append(attr);
    }
}

void DBagent::dropHeader_Attr (QString tableName, int index)
{
    if (tableName == "Staff")
    {
        m_tableStaff->staffHeaderList.removeAt(index);
        m_tableStaff->staffAttrNameList.removeAt(index);
    }
}


