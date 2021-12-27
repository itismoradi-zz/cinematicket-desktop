#include "../include/movie.hpp"

void Movie::setReleaseDate(int date)
{
    releaseDate = date;
}
void Movie::setMovieId(int id)
{
    movieId = id;
}
void Movie::setDirectorName(QString name)
{
    directorName = name;
}
void Movie::setMovieName(QString name)
{
    movieName = name;
}
void Movie::setGenre(QString gnr)
{
    genre[1] = gnr;
}
void Movie::setCast(QString name)
{
    if (numOfCast < 20)
    {
        cast[numOfCast] = name;
        numOfCast++;
    }
    else
    {
        throw(false);
    }
}

int Movie::getReleaseDate()
{
    return releaseDate;
}
int Movie::getNumberOfStars()
{
    return numberOfStars;
}
int Movie::getMovieId()
{
    return movieId;
}
QString Movie::getDirectorName()
{
    return directorName;
}
QString Movie::getMovieName()
{
    return movieName;
}
QString Movie::getGenre()
{
    return genre[0];
}
QString Movie::getCast()
{
    return cast[1];
}

void Movie::addToStars()
{
    numberOfStars++;
}
