#include <iostream>
using namespace std;
   void changeA(int* ptr){
            *ptr = 20;
        }
int main(){
    // int a = 10;
    // int* ptr = &a;
    // int** parptr = &ptr;//**store the address of another pointer 
    // cout << &ptr << endl;//0x1dcc9ffa88
    // cout << parptr << endl;//0x1dcc9ffa88
    // // dereference operater
    // cout << *(&a) <<endl; //10
    // cout << *(ptr) <<endl;//10
    // int** parPtr = &ptr;
    // cout << *(parPtr) <<endl;//0xa60bdffe0c
    // cout << (ptr) <<endl;//0xa60bdffe0c
    // cout << **(parPtr) <<endl;//10
    //null pointer
    // int** ptr = NULL;
    // cout<< ptr << endl; //memory address null, output will be 0
    // cout<< *ptr << endl;
    // Pass by reference
 
    
    int a = 10;
    changeA(&a);
    cout<<"inside main function : "<<a<<endl;//20
    
   
}