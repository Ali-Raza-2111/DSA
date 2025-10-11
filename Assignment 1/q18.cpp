#include <iostream>
using namespace std;

int main() {
    int arr[10] = {10, 20, 40, 50, 60}; 
    int n = 5;  
    int newElement = 30; 
    int pos = 2;

   
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    
    arr[pos] = newElement;
    n++;  

    cout << "Array after insertion:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
