#ifndef SIGNUP_HPP
#define SIGNUP_HPP

#include <QMainWindow>
#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class signUp;
}

class signUp : public QMainWindow
{
    Q_OBJECT

public:
    signUp(QWidget *parent,QSqlDatabase *);
    ~signUp();
    void signUpCustomer();
    void signUpManager();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::signUp *ui;
    QSqlDatabase * db;
};


#endif // SIGNUP_HPP
