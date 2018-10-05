#ifndef DROPCOLUMN_H
#define DROPCOLUMN_H

#include"Database/DBagent.h"

#include <QWidget>
#include <QString>

namespace Ui {
class DropColumn;
}

class DropColumn : public DBagent
{
    Q_OBJECT

public:
    explicit DropColumn(QWidget *parent = 0);
    ~DropColumn();

    ///*界面数据公有接口*///
    int getDropAttrNameIndex (void );

signals:
    void signalBeginDropColumn ();

public slots:
    void slotDropStaffColumn ();


private slots:
    void on_pushButtonBeginDropColumn_clicked();

private:
    Ui::DropColumn *ui;
};

#endif // DROPCOLUMN_H
