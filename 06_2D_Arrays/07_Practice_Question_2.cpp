#include <iostream>
using namespace std;

int main(){
    const int rows= 3,col = 3; 
    int matrix[rows][col]= { {1,4,9}, {11,4,3}, {2,2,3} };
    int sum = 0;
    for (int i = 0; i < col; i++)
    {
        sum+=matrix[1][i];
    }

    cout<<"Sum is "<<sum<<endl;
    
    return 0;
}