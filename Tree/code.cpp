#include <iostream>
using namespace std;
//    void changeA(int* ptr){ //pass by reference by pointers
   void changeA(int &b){ //pass by reference by alias
            b = 20;
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
 
    
    // int a = 10;
    // // changeA(&a); //pointers
    // changeA(a);//alias
    // cout<<"inside main function : "<<a<<endl;//20
    //array pointer
    
    // cout<<*arr<<endl;//pointer=>1
    // cout<<*(arr + 1) <<endl;//pointer=>2
    // cout<<*(arr + 2) <<endl;//pointer=>3
    // cout<<*(arr + 3) <<endl;//pointer=>4
    // cout<<*(arr + 4) <<endl;//pointer=>5
    // pointer arithmetic
    // int a = 10;
    // int* ptr = &a;
    // cout <<ptr <<endl;
    // ptr = ptr + 2;
    // cout << ptr <<endl; //+4
    // return 0;
//   relational operators 
// int arr[] = {1,2,3,4,5};
// int* ptr1;
// // int* ptr2 ;
// int* ptr2 = ptr1;
// cout << ptr1 << endl;
// cout <<ptr2 <<endl;
// cout <<(ptr1 == ptr2) <<endl;
// cout <<(ptr1 != ptr2) <<endl;
// cout <<(ptr1 > ptr2) <<endl;
// cout <<(ptr1 < ptr2) <<endl;
// return 0;
// question of array pointer 
int arr[] = {10,20,30,40};
int* ptr = arr;
cout << *(ptr + 1) <<endl;
cout <<*(ptr + 3) <<endl;
ptr++;
cout <<*ptr <<endl;
return 0;
    
   
}