#ifndef WAITWIDGET_H
#define WAITWIDGET_H

#include <QWidget>

namespace Ui {
class WaitWidget;
}

class WaitWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WaitWidget(QWidget *parent = 0);
    ~WaitWidget();

private:
    Ui::WaitWidget *ui;
};

#endif // WAITWIDGET_H
