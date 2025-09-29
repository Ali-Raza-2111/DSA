#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    string cnic; 

public:
    Person() {
        name = "";
        age = 0;
        cnic = "";
    }

    void setName(const string &n) {
        name = n;
    }


    bool setAge(int a) {
        if (a >= 0 && a <= 130) {
            age = a;
            return true; 
        } else {
            cout << "Invalid age! Must be between 0 and 130.\n";
            return false; // invalid
        }
    }

    bool setCNIC(const string &c) {
        if (c.length() == 13) {
            cnic = c;
            return true; 
        } else {
            cout << "Invalid CNIC! Must be exactly 13 digits.\n";
            return false; 
        }
    }

    string getName() const {
        return name;
    }


    int getAge() const {
        return age;
    }


    string getCNIC() const {
        return cnic;
    }


    void Print() const {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nCNIC: " << cnic << endl;
    }
};

int main() {
    Person p;

    string n, c;
    int a;

    cout << "Enter Name: ";
    getline(cin, n);
    p.setName(n);

    cout << "Enter Age: ";
    cin >> a;

    while (!p.setAge(a)) {
        cout << "Re-enter Age: ";
        cin >> a;
    }

    cin.ignore(); 
    cout << "Enter CNIC number (13 digits): ";
    getline(cin, c);
    while (!p.setCNIC(c)) {
        cout << "Re-enter CNIC: ";
        getline(cin, c);
    }

    cout << "\nPerson details:\n";
    p.Print();

    return 0;
}
