#ifndef ADDCOLUMN_H
#define ADDCOLUMN_H
#include"Database/DBagent.h"

#include <QWidget>
#include <QString>

namespace Ui {
class AddColumn;
}

class AddColumn : public DBagent
{
    Q_OBJECT

public:
    explicit AddColumn(QWidget *parent = 0);
    ~AddColumn();

    ///*界面数据公有接口*///
    QString getNewHeaderName (void) const;
    QString getNewAttrName (void) const;
    QString getNewAttrType (void) const;

signals:
    void signalBeginAddColumn ();

public slots:
    void slotAddColumn ();

private slots:
    void on_pushButtonBeginAddAColumn_clicked();

private:
    Ui::AddColumn *ui;
};

#endif // ADDCOLUMN_H
