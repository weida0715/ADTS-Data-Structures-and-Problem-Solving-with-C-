#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    const double PI = 3.14159265359;
    double radius;                         // radius of a sphere
    int count = 0;                         // number of spheres processed
    string END_OF_FILE_MARK = "Control-C"; // for Unix systems

    for (;;) // loop:
    {
        cout << "Enter radius of sphere (("
             << END_OF_FILE_MARK << " to stop): ";
        cin >> radius; // get next radius

        if (cin.eof())
            break; // end of data
        count++;

        double volume = 4.0 * PI * pow(radius, 3) / 3.0; // output the results

        cout << "Volume of sphere of radius " << radius
             << " is " << volume << " cubic inches.\n\n"; // end loop
    }

    // Output data count
    cout << endl
         << count << " spheres processed\n";
}
