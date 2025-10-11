#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int arr[rows][cols];
    int sum = 0;
    float avg;

    cout << "Enter elements of the 2D array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    avg = (float)sum / (rows * cols);  

    cout << "\nSum of elements = " << sum << endl;
    cout << "Average of elements = " << avg << endl;

    return 0;
}
