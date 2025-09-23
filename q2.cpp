#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a three-digit number: ";
    cin >> num;

    if (num < 100 || num > 999) {
        cout << "Please enter a valid three-digit number." << endl;
        return 0;
    }

    int hundreds = num / 100;
    int tens = (num / 10) % 10;
    int ones = num % 10;

    int reversed = ones * 100 + tens * 10 + hundreds;

    cout << "Reversed number: " << reversed << endl;

    return 0;
}
