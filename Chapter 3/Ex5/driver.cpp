/*
    Driver program to test Time library.
*/

#include <iostream>
using namespace std;
#include "Time.h"

int main()
{
    Time mealTime,
        goToWorkTIme;

    set(mealTime, 5, 30, 'P');
    cout << "We'll be eating at ";
    display(mealTime, cout);
    cout << endl;

    set(goToWorkTIme, 5, 30, 'P'); // Try other values also: 'A' -> 'P'
    cout << "You leave for work at ";
    display(goToWorkTIme, cout);
    cout << endl;

    if (lessThan(mealTime, goToWorkTIme))
        cout << "If you hurry, you can eat first.\n";
    else
        cout << "Sorry you can't eat with us.\n";

    advance(goToWorkTIme, 0, 30); // Try other values also: 0 -> 12
    cout << "Your boss called. You go in later at ";
    display(goToWorkTIme, cout);
    cout << endl;

    if (lessThan(mealTime, goToWorkTIme))
        cout << "If you hurry, you can eat first.\n";
    else
        cout << "Sorry you can't eat with us.\n";

    cout << endl;
}
