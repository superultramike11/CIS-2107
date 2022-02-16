#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 5

int sumEvenNumbers(int array[], int size);

int main() {
    int array[SIZE] = {1,2,3,4,5};

    sumEvenNumbers(array, SIZE);

    return 0;
}

int sumEvenNumbers(int array[], int size) {
    int sum = 0;

    for(int i=0; i<SIZE; ++i) {
        if(array[i] % 2 == 0) {
            sum += array[i];
        }
    }
    printf("Sum = %d", sum);
    return sum;
}
