#include <iostream>
using namespace std;

void tablePrint(int num,int multiplier){
    for (int i = 1; i <= multiplier; i++)
    {
        cout<<num<<" * "<<i<<" = "<<num*i<<endl;
    }
    
}
int main(){
    int table = 5;
    int multiplier = 7;
    tablePrint(table,multiplier);
    return 0;
}