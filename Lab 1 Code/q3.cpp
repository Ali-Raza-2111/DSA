#include <iostream>
using namespace std;

int main(){
    string num ;
    cout<<"Enter a digit ";
    getline(cin,num);

    for(char c:num){
        cout<<c<<",";
    }
    return 0;
}