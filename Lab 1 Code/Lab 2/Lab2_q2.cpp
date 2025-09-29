#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int marks[3];  

public:
    void inputData() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore(); 
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter marks in 3 subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }

    int failed() {
        int failCount = 0;
        for (int i = 0; i < 3; i++) {
            if (marks[i] < 40) { 
                failCount++;
            }
        }
        return failCount;
    }


    void display() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: ";
        for (int i = 0; i < 3; i++) {
            cout << marks[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Student students[3];

    cout << "Enter details of 3 students:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nStudent " << (i + 1) << ":\n";
        students[i].inputData();
    }

    cout << "\nStudents who failed in more than one subject:\n";
    for (int i = 0; i < 3; i++) {
        int fail = students[i].failed();
        cout<<"Student"<<i+1<<"failed in "<<fail<<" Subjects"<<endl;
    }

    return 0;
}
