#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <QMainWindow>
#include <QString>
#include <QSqlDatabase>

namespace Ui {
class Profile;
}

class Profile : public QMainWindow
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent, QString, QSqlDatabase *, bool);
    ~Profile();
    void getInformation();
    void getCustomerInfo();
    void getManagerInfo();
    void getWallet();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Profile *ui;
    QString ID;
    QSqlDatabase * db;
        bool isManager;
};

#endif // PROFILE_HPP
