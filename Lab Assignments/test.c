#include <stdio.h>
#define SIZE 20

size_t getSize(float *ptr);

int main() {
    float array[SIZE];

    printf("The number of bytes in the array is %u"
           "\nThe number of bytes returned by getSize is %u\n",
           sizeof(array), getSize(array));
}

size_t getSize(float *ptr) {
    return sizeof(ptr);
}
