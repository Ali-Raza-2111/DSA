#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    cout << "Enter a number: ";
    cin >> num;

    int sum = 0;

    cout << "Digits: ";
    for (char c : num) {
        if (isdigit(c)) {
            cout << c << " ";
            sum += c - '0';
        }
    }

    cout << "\nSum of digits: " << sum << endl;

    return 0;
}
