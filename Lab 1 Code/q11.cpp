#include <iostream>
using namespace std;

int main(){
    int spaces = 1;
    string s;
    cout<<"Enter a string\t";
    getline(cin,s);
    
    for(char c:s){
        if (c==' ')
        {
            spaces++;
        }
        
    }

    cout<<"Total Spaces "<<spaces<<endl;

    return 0;
}