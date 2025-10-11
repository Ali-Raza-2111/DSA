#include <iostream>
using namespace std;

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;

   
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;

    cout << "After deleting first element:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    
    int pos = 2; 
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;

    cout << "After deleting element at position 2:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    
    n--;

    cout << "After deleting last element:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
