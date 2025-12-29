#include <iostream>
using namespace std;

int main(){
    const int row = 2, col = 3;
    int target = 7,count = 0;
    int matrix[row][col]=  { {4,7,8}, {8,8,7} };
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == target)
            {
                count++;
            }
            
        }
        
    }
    cout<<count<<endl;
    return 0;
}