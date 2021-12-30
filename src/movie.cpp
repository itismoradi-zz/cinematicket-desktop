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
bool Movie::setGenre(QString gnr)
{
    gnr = gnr.toLower();
    if (gnr == "comedy" || gnr == "drama" || gnr == "documentry" || gnr == "romantic" || gne == "action")
    {
        movieGenres.push_front(gnr);
        return true;
    }
    return false;
}
void Movie::setCast(QString name) // adds a new cast to vector
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
const QVector &<QString> Movie::getGenre()
{
    return movieGenres;
}
const QVector &<QString> Movie::getCast()
{
    return cast;
}

void Movie::addToStars()
{
    numberOfStars++;
}
