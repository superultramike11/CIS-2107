/*
    Name: Michael Ewing
    Date: 2/03/2022
    Course: CIS 2107 Sec 001
    HW #: Lab 04
    Statement of Problem: To design and implement functions to process 1D Arrays
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 40
#define RAND_MIN 0
#define RAND_MAX 100

void fillArray(int array[], int size);

int main(void) {
    int array[SIZE];

    fillArray(array, SIZE);
    //findWithRange(array, SIZE);
    //reverseArray(array, SIZE);
    //reverseSelectedRangeWithinArray(array, SIZE);
    //findSequence(array, SIZE);
}

void printArray(int array[], int size) {
    for(int i=1; i<=SIZE; i++) {
        printf("%10d", array[i]);
        if(i % 10 == 0) {
            puts("");
        }
    }
}

// Fills a 1D array with random integers. Integers are picked in the range rand_min to rand_max (inclusive)
void fillArray(int array[], int size) {
    srand((unsigned)time(NULL));
    for(size_t i=1; i<=SIZE; ++i) {
        array[i] = rand() % (RAND_MAX+1) + RAND_MIN;
    }
    printArray(array, SIZE);
    puts("");
}

// Locates the largest element in a range of the same array.
void findWithRange(int array[], int size) {
    fillArray(array, SIZE);

    int max = 0;
    int lowSelectRange = 10;
    int highSelectRange = 20;

    for(int i=lowSelectRange+1; i<=highSelectRange; ++i) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    printf("Max = %d", max);
}

// Reverses the order of the array elements
void reverseArray(int array[], int size) {
    puts("Original:");
    fillArray(array, SIZE);

    puts("Reversed");
    for(int low=0, high = SIZE+1; low<high; low++, high--) {
        int temp = array[low];
        array[low] = array[high];
        array[high] = temp;
    }

    printArray(array, SIZE);
}

// Reverses the order of the array elements in a range between two indexes, startRange and endRange
void reverseSelectedRangeWithinArray(int array[], int size) {
    puts("Original:");
    fillArray(array, SIZE);

    int userLow = 15;
    int userHigh = 24;

    printf("Reversing between %d and %d\n\n", userLow, userHigh);
    for(int low=userLow+1, high = userHigh+1; low<high; low++, high--) {
        int temp = array[low];
        array[low] = array[high];
        array[high] = temp;
    }
    printArray(array, SIZE);
}

// Looks for two adjacent integers in the array, return index of first element or -1 if sequence isn't present
void findSequence(int array[], int size) {
    fillArray(array, SIZE);
    int tom = 69;
    int jerry = 65;
    bool found = false;

    for(int i=1; i<=SIZE-1; ++i) {
        if(array[i] == tom && array[i+1] == jerry) {
            printf("sequence found at index %d", i);
            found = true;
        }
    }
    if(found == false) {
        puts("sequence not found");
    }
}
