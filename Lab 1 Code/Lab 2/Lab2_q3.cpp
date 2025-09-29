#include <iostream>
using namespace std;


void AscendingSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int SIZE = 10;
    int numbers[SIZE];

   
    cout << "Enter 10 integers: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> numbers[i];
    }

    
    AscendingSort(numbers, SIZE);

    cout << "\nNumbers in ascending order: ";
    for (int i = 0; i < SIZE; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
