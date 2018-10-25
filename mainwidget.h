#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private slots:
    void on_pushButtonClose_clicked();

    void on_pushButtonMax_clicked();

    void on_pushButtonMin_clicked();


protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

private:
    Ui::MainWidget *ui;

    QPoint m_widgetMove;    //定义一个QPoint对象用于界面移动；
};

#endif // MAINWIDGET_H
