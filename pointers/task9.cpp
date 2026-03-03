#include <stdio.h>
int main(){
    int x = 5;
    int* p = &x;
    int* q = p;
    *q = 100;
    printf("%d",x);
    
}