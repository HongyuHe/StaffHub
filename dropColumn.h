#ifndef DROPCOLUMN_H
#define DROPCOLUMN_H

#include <QWidget>

namespace Ui {
class DropColumn;
}

class DropColumn : public QWidget
{
    Q_OBJECT

public:
    explicit DropColumn(QWidget *parent = 0);
    ~DropColumn();

private:
    Ui::DropColumn *ui;
};

#endif // DROPCOLUMN_H
