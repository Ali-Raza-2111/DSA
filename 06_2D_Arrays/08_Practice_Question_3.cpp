#include <iostream>
using namespace std;

int main(){
    const int rows = 4,cols = 4;
    int matrix[rows][cols] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<<matrix[j][i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}