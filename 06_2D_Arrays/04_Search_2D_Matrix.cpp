#include <iostream>
using namespace std;

// Function to search in a specific row using binary search
bool searchInRow(int matrix[][3], int target, int row, int n) {
    int st = 0, end = n - 1;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (target == matrix[row][mid]) {
            return true;
        } else if (target > matrix[row][mid]) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

// Function to search in the whole matrix
bool searchMatrix(int matrix[][3], int m, int n, int target) {
    int startRow = 0, endRow = m - 1;
    while (startRow <= endRow) {
        int midRow = startRow + (endRow - startRow) / 2;
        if (target >= matrix[midRow][0] && target <= matrix[midRow][n - 1]) {
            // Target could be in this row
            return searchInRow(matrix, target, midRow, n);
        } else if (target > matrix[midRow][n - 1]) {
            startRow = midRow + 1;
        } else {
            endRow = midRow - 1;
        }
    }
    return false;
}

int main() {
    int matrix[2][3] = {{1, 2, 3},
                        {4, 5, 6}};

    int target = 5;
    if (searchMatrix(matrix, 2, 3, target))
        cout << "Found " << target << " in matrix\n";
    else
        cout << "Not found\n";

    return 0;
}
