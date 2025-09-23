#include <iostream>
using namespace std;

int GetUpperLimit() {
    int limit;
    while (true) {
        cout << "Enter upper limit (<= 1000): ";
        cin >> limit;
        if (limit <= 1000 && limit > 0) {
            return limit;           
        }
        cout << "Invalid input. Please enter a number between 1 and 1000.\n";
    }
}

int SumOfEven(int limit) {
    int sum = 0;
    int i = 2;                      
    while (i <= limit) {
        sum = sum + i;
        i = i + 2;                  
    }
    return sum;
}

int main() {
    int upperLimit = GetUpperLimit();
    int sum = SumOfEven(upperLimit);
    cout << "Sum of even numbers up to " << upperLimit << " is: " << sum << endl;
    return 0;
}
