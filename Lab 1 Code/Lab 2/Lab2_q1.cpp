#include <iostream>
using namespace std;

void getChoice(char &ch){
    cout<<"Enter Your Choice(s,r,c)";
    cin>>ch;
}

float squareArea(float len){
    return len*len;
}

float rectangleArea(float len,float wid){
    return len*wid;
}

float circleArea(float r){
    return 3.14 * r *r;
}

void CalculateArea(char choice){
    float area;
    if (choice == 's')
    {
        float len;
        cout<<"Enter the length\t";
        cin>>len;
        area = squareArea(len);
        cout<<"Area is "<<area;
    }
    if (choice == 'r')
    {
        float len,wid;
        cout<<"Enter the length\t";
        cin>>len;
        cout<<"Enter width\t";
        cin>>wid;
        area = rectangleArea(len,wid);
        cout<<"Area is "<<area;
    }
    if (choice == 'c')
    {
        float r;
        cout<<"Enter the radius\t";
        cin>>r;
        area = circleArea(r);
        cout<<"Area is "<<area;
    }
    
}
int main(){
    char shape;
    getChoice(shape);
    CalculateArea(shape);
    return 0;
}