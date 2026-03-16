#include <iostream>
using namespace std;
int main(){
    char ch;
    cout<<"Enter Character :";
    cin>>ch;
    if(ch >=65 && ch <=90){ //implicit conversion
        cout<< "Uppercase";
             
    } else{
        cout<<"Lowercase";
    }
    return 0;
}