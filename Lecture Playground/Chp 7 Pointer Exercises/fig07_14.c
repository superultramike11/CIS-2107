// Attempt to modify a constant pointer to constant data
#include <stdio.h>

int main(void) {
    int x = 5;
    int y;

    const int *const ptr = &x;

    printf("%d\n", *ptr);
    //*ptr = 7; // can't reassign a value to a const variable
    //ptr = &y; // can't assign new address
}
