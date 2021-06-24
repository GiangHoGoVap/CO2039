#include <iostream>
#include "Movie.cpp"

using namespace std;

int main()
{
    Movie up(1083, "Up", 2009, 8.6);
    Movie hp(1127, "Harry Potter and the Half-Blood Prince", 2009, 7.5);

    cout << up.getId() << up.getName() << up.getYear() << up.getRating() << endl;

    cout << hp << endl;
    if (up < hp)
    {
        cout << "Up is older/lower ranked than Harry Potter" << endl;
    }
    else
    {
        cout << "Harry Potter is older/lower ranked than Up" << endl;
    }
    return 0;
}