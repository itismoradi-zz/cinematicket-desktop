#include "../include/movie.hpp"

void Movie::setReleaseDate(int date)
{
    releaseDate = date;
}
void Movie::setId(int id)
{
    Id = id;
}
void Movie::setDirectorName(QString name)
{
    directorName = name;
}
void Movie::setName(QString movieName)
{
    name = movieName;
}
void Movie::setGenre(QString gnr)
{
    movieGenres.push_front(gnr);
}
void Movie::setCast(QString name)   // adds a new cast to vector
{
    cast.push_front(name);
}
int Movie::getReleaseDate()
{
    return releaseDate;
}
int Movie::getNumberOfStars()
{
    return numberOfStars;
}
int Movie::getId()
{
    return Id;
}
QString Movie::getDirectorName()
{
    return directorName;
}
QString Movie::getName()
{
    return name;
}
const QVector<QString> Movie::getGenre()
{
    return movieGenres;
}
const QVector<QString> Movie::getCast()
{
    return cast;
}

void Movie::addToStars()
{
    numberOfStars++;
}
