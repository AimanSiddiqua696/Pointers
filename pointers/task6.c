#include <stdio.h>

// Function definition OUTSIDE main
void swap(int *a, int *b) {
    int temp = *a; //Go to the address stored in a and get the value
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;

    swap(&x, &y);

    printf("x = %d, y = %d", x, y);

    return 0;
}