#include <stdio.h>

void swap(int **a, int **b) {
    int *temp = *a;   // store pointer
    *a = *b;          // swap pointers
    *b = temp;
}

int main() {

    int x = 5, y = 10;

    int *p1 = &x;
    int *p2 = &y;

    swap(&p1, &p2);

    printf("After swap:\n");
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %d\n", *p2);

    return 0;
}