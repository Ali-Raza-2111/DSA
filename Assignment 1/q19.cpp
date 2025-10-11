#include <iostream>
#include <cstdlib>  
using namespace std;

int main() {
    int n = 5;
    int *arr = (int*) malloc(n * sizeof(int));

    
    int initialValues[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < n; i++)
        arr[i] = initialValues[i];

    
    int newElement = 60;

    
    arr = (int*) realloc(arr, (n + 1) * sizeof(int));

    
    arr[n] = newElement;
    n++;

    
    cout << "Array after insertion:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    free(arr);

    return 0;
}
