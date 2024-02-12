#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double PI = 3.14159265359;
    double radius; // radius of a sphere
    int count = 0; // number of spheres processed

    cout << "Enter radius of sphere (o to stop!): ";
    cin >> radius; // get first radius

    while (radius > 0) // while not end-of-data
    {
        count++;
        double volume = 4.0 * PI * pow(radius, 3) / 3.0; // output the results

        cout << "Volume of sphere of radius " << radius
             << " is " << volume << " cubic inches.\n\n"; // end loop

        cout << "Enter radius of sphere (o to stop!): ";
        cin >> radius; // get next radius
    }                  // end while

    // Output data count
    cout << endl
         << count << " spheres processed\n";
}