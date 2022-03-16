#include <stdio.h>

int fun(int *a, int *b);

int main() {
    int x = 10, y = 20;
    fun(&x, &y);
    printf("x = %d y = %d\n", x,y);
}

int fun(int *a, int *b) {
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}
