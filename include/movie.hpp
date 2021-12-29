#ifndef MOVIE_H
#define MOVIE_H

#include <QString>
#include <QVector>

class Movie
{
public:
    void setReleaseDate(int);
    void setId(int);
    void setDirectorName(QString);
    void setName(QString);
    void setGenre(QString);
    void setCast(QString);

    int getReleaseDate();
    int getNumberOfStars();
    int getId();
    QString getDirectorName();
    QString getName();
    const QVector<QString> getCast();
    const QVector<QString> getGenre();

    void addToStars();

private:
    int releaseDate;
    int numberOfStars = 0;
    int Id;
    QString directorName;
    QString name;
    QString genres[5] = {"comedy", "drama", "action", "romance", "documentry"};   // genres a movie can have
    QVector <QString> movieGenres;
    QVector <QString> cast;
};

#endif // MOVIE_H
