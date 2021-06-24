#include <iostream>
#include "Movie.h"

Movie::Movie(int id, string name, int year, double rating)
{
    this->id = id;
    this->name = name;
    this->year = year;
    this->rating = rating;
}

const int Movie::getId()
{
    return this->id;
}

const string Movie::getName()
{
    return this->name;
}

const int Movie::getYear()
{
    return this->year;
}

const double Movie::getRating()
{
    return this->rating;
}

ostream &operator<<(ostream &ostr, const Movie &m)
{
    ostr << "<* " << m.id << " " << m.name << " " << m.year << " " << m.rating << " *>";
    return ostr;
}

bool operator<(const Movie &lhs, const Movie &rhs)
{
    if (lhs.year == rhs.year)
    {
        if (lhs.rating < rhs.rating)
            return true;
        else
            return false;
    }
    return (lhs.year < rhs.year);
}