#include <iostream>
using namespace std;
void spiralMatrix(int martix[][4],int n,int m){
    int srow = 0,scol= 0;
    int erow = n-1,ecol = m-1;
    while(srow<=erow && scol<=ecol){

    for(int i = scol;i<=ecol;i++){
        cout<<martix[srow][i]<<" ";
    }
    cout<<endl;
    for(int i = srow+1;i<=erow;i++){
        cout<<martix[i][ecol]<<" ";
    }
    cout<<endl;
    if(srow<erow){
        for (int i = ecol-1; i >=scol; i--)
        {
            
            
            cout<<martix[erow][i]<<" ";
        }
        cout<<endl;
    }
    if (scol<ecol)
    {
        for(int i = erow-1;i>=srow+1;i--){
            cout<<martix[i][scol]<<" ";
        }
        cout<<endl;
    }
    

        srow++;
        scol++;
        ecol--;
        erow--;
    }
    
    
}
int main(){
    int matrix[4][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};
    
    int matrix2[3][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12}};
    spiralMatrix(matrix2,3,4);
    
    return 0;
}   