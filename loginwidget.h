#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include <QPoint>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

signals:
    void signalLoginClicked ();
    void signalRegisterClicked ();

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

    Ui::LoginWidget *ui;

    QString get_m_adminName () const;
    QString get_m_adminPswd () const;

    void setUI_lineEditCheckLogin (QString checkLogin);

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

private slots:
    void on_pushButtonLogin_clicked();

    void on_pushButtonRegister_clicked();

private:
    QString m_adminName;
    QString m_adminPswd;

    QPoint m_widgetMove;    //定义一个QPoint对象用于界面移动；
};

#endif // LOGINWIDGET_H
