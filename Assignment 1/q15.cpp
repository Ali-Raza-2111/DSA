#include <iostream>
#include <cstdlib>  
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

   
    int *arr = (int*) malloc(n * sizeof(int));

    if (arr == NULL) {
        cout << "Memory allocation failed!";
        return 1;
    }

   
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    
    cout << "You entered:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    
    free(arr);

    return 0;
}
