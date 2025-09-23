#include <iostream>
using namespace std;

long long FactorialIterative(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

long long FactorialRecursive(int n) {
    if (n == 0 || n == 1) {
        return 1;                
    }
    return n * FactorialRecursive(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 0;
    }

    cout << "Factorial of " << num << " (iterative): " << FactorialIterative(num) << endl;
    cout << "Factorial of " << num << " (recursive): " << FactorialRecursive(num) << endl;

    return 0;
}
