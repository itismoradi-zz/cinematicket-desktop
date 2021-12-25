#ifndef MOVIE_H
#define MOVIE_H

class Movie
{
public:
    void setReleaseDate(int);
    void setMovieId(int);
    void setDirectorName(QString);
    void setMovieName(QString);
    void setGenre(QString);
    void setCast(QString);

    int getReleaseDate();
    int getNumberOfStars();
    int getMovieId();
    QString getDirectorName();
    QString getMovieName();
    QString getGenre();
    QString getCast();
    
    void addToStars();

private:
    int releaseDate;
    int numberOfStars = 0;
    int movieId;
    QString directorName;
    QString movieName;
    QString genre[3];   // each movie can have 3 genres
    QString cast[20];   // each movie has 20 actor or actress or less

    int numOfGenres = 0;
    int numOfCast= 0;

};

#endif // MOVIE_H