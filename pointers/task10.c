// #include <stdio.h>
// int main(){
//     int* func();
//     {
//     int x = 10;
//     return &x;
// }
#include <stdio.h>
#include <stdlib.h>

int* func() {
    int *x = (int*) malloc(sizeof(int)); // allocate memory in heap
    *x = 10;
    return x;  // safe
}

int main() {
    int *p = func();
    printf("%d\n", *p); // prints 10
    free(p);            // free memory
    p = NULL;           // avoid dangling pointer
    return 0;
}
