#ifndef MOVIE_H
#define MOVIE_H

#include <string.h>

using namespace std;

class Movie
{
public:
    // This constructor takes the Movie's ID number, the Movie's name, the year the Movie was made, and the rating of the Movie.
    Movie(int id, string name, int year, double rating);
    // Returns the Movie's individual ID.
    const int getId();
    // Returns the name of the Movie.
    const string getName();
    // Returns the year the Movie was made.
    const int getYear();
    // Returns the rating (out of 10) of the movie
    const double getRating();
    // Prints the complete information of the Movie to the ostream and returns the ostream
    friend ostream &operator<<(ostream &ostr, const Movie &m);
    // Returns a boolean that is true if the Movie on the left of the '<' symbol is less than the Movie on the right.
    // Movie A is deemed less than Movie B if Movie A was made before Movie B or Movie A & B were made the same year
    // and Movie A has a lower rating than Movie B.
    friend bool operator<(const Movie &lhs, const Movie &rhs);

private:
    int id;
    string name;
    int year;
    double rating;
};
#endif