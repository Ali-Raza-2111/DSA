#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr1[n], arr2[n];  
    int *p1 = arr1;        
    int *p2 = arr2;       

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> *(p1 + i);  

    
    for (int i = 0; i < n; i++)
        *(p2 + i) = *(p1 + i);

    cout << "Copied array elements:\n";
    for (int i = 0; i < n; i++)
        cout << *(p2 + i) << " ";

    return 0;
}
