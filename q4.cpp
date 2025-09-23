#include <iostream>
using namespace std;

int main() {
    double radius;
    cout << "Enter radius of the circle: ";
    cin >> radius;

    double diameter = radius * 2;
    double circumference = 2 * 3.14 * radius;
    double area = 3.14 * radius * radius;

    cout << "Diameter: " << diameter << endl;
    cout << "Circumference: " << circumference << endl;
    cout << "Area: " << area << endl;

    return 0;
}
