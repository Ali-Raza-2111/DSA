#include <iostream>
using namespace std;


int countEven(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int* numbers = new int[size]; 

    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    int evenCount = countEven(numbers, size);

    cout << "\nNumber of even integers: " << evenCount << endl;

    delete[] numbers; 
    return 0;
}
