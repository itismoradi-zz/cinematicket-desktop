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
    genre = gnr;
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
    return genre;
}
QString Movie::getCast()
{
    return cast;
}

void Movie::addToStars()
{
    numberOfStars++;
}