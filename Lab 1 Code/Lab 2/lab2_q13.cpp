#include <iostream>
using namespace std;


double area(const double *side) {
    return (*side) * (*side);
}

double area(const double *length, const double *width) {
    return (*length) * (*width);
}

double area(const double *radius, bool circle) {
    const double pi = 3.141592653589793;
    return pi * (*radius) * (*radius);
}

int main() {
    double s, l, w, r;

    cout << "Enter side of square: ";
    cin >> s;
    cout << "Area of square = " << area(&s) << endl;

    cout << "Enter length and width of rectangle: ";
    cin >> l >> w;
    cout << "Area of rectangle = " << area(&l, &w) << endl;

    cout << "Enter radius of circle: ";
    cin >> r;
    cout << "Area of circle = " << area(&r, true) << endl;

    return 0;
}
