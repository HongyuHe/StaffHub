#ifndef ADVANCEDFILTER_H
#define ADVANCEDFILTER_H

#include <QWidget>

class QString;

#include"Database/DBagent.h"

namespace Ui {
class AdvancedFilter;
}

class AdvancedFilter : public DBagent/*public QWidget*/
{
    Q_OBJECT

signals:
    void signalBeginFilter ();

public:
    explicit AdvancedFilter(QWidget *parent = 0);
    ~AdvancedFilter();

    ///*界面数据公有接口*///
    int getField () const;
    QString getCompareOperator () const;
    QString getConditionValue () const;

public slots:
    void slotStaffTableFilter ();

private slots:
    void on_pushButtonBeginFilter_clicked();

private:
    Ui::AdvancedFilter *ui;
};

#endif // ADVANCEDFILTER_H
