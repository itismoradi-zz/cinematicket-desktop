#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "signup.hpp"

namespace Ui {
    class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    void logIn(QString, QString);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_signUp_clicked();

private:
    Ui::login *ui;
    QSqlDatabase db;
    signUp * signUpWindow;
};

#endif // LOGIN_HPP
