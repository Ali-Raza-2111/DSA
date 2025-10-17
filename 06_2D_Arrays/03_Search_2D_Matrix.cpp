#include <iostream>
using namespace std;

bool searchMatrix(int matrix[][3], int n, int target) {
    int m = 2,n = 3;
    int startRow = 0,endRow = m-1;
    while (startRow<endRow)
    {
        int midRow = startRow + (endRow-startRow)/2;
        if (target >= matrix[midRow][0] && target <=matrix[midRow][n-1] )
        {
            
        }else if (target > matrix[midRow][n-1])
        {
            startRow = midRow+1;
        }else{

        }
        
        
    }
    
}

int main() {
    int matrix[2][3]= {{1,2,3},
                        {4,5,6}};

    searchMatrix(matrix);

    return 0;
}
