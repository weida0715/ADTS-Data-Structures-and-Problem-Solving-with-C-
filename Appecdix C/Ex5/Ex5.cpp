#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{

    const double PI = 3.14159265359;
    double radius;
    int count = 0;
    char response; // user response to "More data?"

    cout << showpoint << fixed << setprecision(3);

    do
    {
        cout << "Enter radius of sphere: ";
        cin >> radius; // get next radius
        count++;

        double volume = 4.0 * PI * pow(radius, 3) / 3.0;
        cout << "Volume of sphere of radius " << radius
             << " is " << volume << " cubic inches.\n\n";

        cout << "More data (Y or N)? ";
        cin >> response;
    } while (response == 'Y' || response == 'y');
}