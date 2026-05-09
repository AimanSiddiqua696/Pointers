#include <stdio.h>

int main() {
    int *p;       // Wild pointer: not initialized
    printf("Pointer p contains garbage address: %p\n", p);

    *p = 10;      // Dereferencing wild pointer → runtime error / crash
    printf("Value at p: %d\n", *p);

    return 0;
}