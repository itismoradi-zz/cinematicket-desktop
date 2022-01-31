#ifndef CINEMAMOVIE_HPP
#define CINEMAMOVIE_HPP

#include <QDialog>
#include <QString>
#include "profile.hpp"
#include <QSqlDatabase>

namespace Ui {
class CinemaMovie;
}

class CinemaMovie : public QDialog
{
    Q_OBJECT

public:
    CinemaMovie(QWidget *parent, QString, QSqlDatabase *, bool);
    ~CinemaMovie();
    void getDataFromDB();
    void setComboBoxs();

private slots:
    void on_btn_profile_clicked();

    void on_btn_search_clicked();

    void on_comboBox_seat_activated(const QString &arg1);

    void on_btn_buyTicket_clicked();

private:
    Ui::CinemaMovie *ui;
    QString userID;
    Profile * userProfileWindow;
    QSqlDatabase * db;
    bool isManager;
};

#endif // CINEMAMOVIE_HPP
