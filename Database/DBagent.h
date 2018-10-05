#ifndef DBAGENT_H
#define DBAGENT_H

#include <QWidget>
#include <QMap>

class TableAdmin;
class TableStaff;
class ViewBasic;

class DBagent : public QWidget
{
    Q_OBJECT

public:
    DBagent(QWidget *parent = 0);
    ~DBagent();

    QStringList findOutAttrList (QString tableName) const;        //搜索对应属性名链表：
    QStringList findOutHeaderList (QString tableName) const;    //搜索对应表头链表：

    void appendHeader_Attr (QString tableName, QString header, QString atr);
    void dropHeader_Attr (QString tableName, int index);
    ///表和视图及其初始化共有接口：
    TableStaff *m_tableStaff;
    void initTableStaff (void );

    ViewBasic *m_viewBasic;
    void initViewBasic (void );

//    ///表单链表内容填充通用方法：
//    template <typename T> //QString的位置？？？
//    void padingList (QString tableName, QList<String> ,T &recordList);

//    QMap<QString, QVariant> DBdata;    /// 【数据库容器】：<表/视图名，表/视图元组链表的地址>
//     ///初始化数据库容器：
//     void initDBmap;

};

#endif // DBAGENT_H
