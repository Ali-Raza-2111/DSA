#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec = {1,2,3,4};
    cout<<"Size:"<<vec.size()<<endl;
    cout<<"Capacity:"<<vec.capacity()<<endl;
    vec.push_back(5);
    cout<<"Size:"<<vec.size()<<endl;
    cout<<"Capacity:"<<vec.capacity()<<endl;

    return 0;
}
