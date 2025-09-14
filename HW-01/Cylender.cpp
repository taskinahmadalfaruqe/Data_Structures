#include <bits/stdc++.h>
using namespace std;

class Cylinder
{
private:
    double radius;
    double height;

public:
    // Constructor
    Cylinder(double r, double h) : radius(r), height(h) {}
    const double PI = 3.1416;

    // Function to calculate bottom (base) area
    double bottomArea()
    {
        return PI * radius * radius;
    }

    // Function to calculate volume
    double volume()
    {
        return bottomArea() * height;
    }

    // Function to calculate surface area
    double surfaceArea()
    {
        return 2 * PI * radius * (radius + height);
    }
};

int main()
{
    double radius, height;

    // Input radius and height
    cout << "Enter radius: " << endl;
    cin >> radius;
    cout << "Enter height: " << endl;
    cin >> height;

    // Create a Cylinder object
    Cylinder cyl(radius, height);

    // Output results
    cout << "Radius Of Cylinder: " << radius << ", Height Of Cylinder: " << height << endl;
    cout << "Bottom Area: " << cyl.bottomArea() << endl;
    cout << "Volume: " << cyl.volume() << endl;
    cout << "Surface Area: " << cyl.surfaceArea() << endl;

    return 0;
}

