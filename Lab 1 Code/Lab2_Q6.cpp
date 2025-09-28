#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:

    void set(int f, float i) {
        feet = f;
        inches = i;

        if (inches >= 12.0) {
            feet += inches / 12;
            inches = static_cast<int>(inches) % 12 + (inches - inches);
        }
    }


    void disp() {
        cout << feet << " feet " << inches << " inches" << endl;
    }

    Distance add(Distance d) {
        Distance temp;
        temp.inches = inches + d.inches;
        temp.feet = feet + d.feet;


        if (temp.inches >= 12.0) {
            temp.feet += temp.inches / 12;
            temp.inches = static_cast<int>(temp.inches) % 12 + (temp.inches - temp.inches);
        }

        return temp;
    }
};

int main() {
    Distance d1, d2, d3;

  
    d1.set(5, 8.5);   
    d2.set(3, 11.75); 


    d3 = d1.add(d2);


    cout << "Distance 1: ";
    d1.disp();

    cout << "Distance 2: ";
    d2.disp();

    cout << "Sum (Distance 3): ";
    d3.disp();

    return 0;
}
