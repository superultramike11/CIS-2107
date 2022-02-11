/*
    Name: Michael Ewing
    Date: 2/03/2022
    Course: CIS 2107 Sec 001
    HW #: Lab 04
    Statement of Problem: To design and implement functions to process 1D Arrays
*/
// Pre-process directives
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Defining constants
#define SIZE 40
#define RAND_MIN 0
#define RAND_MAX 100

// Function prototypes
void printArray(int array[], int size);
void fillArray(int array[], int size);
void findWithRange(int array[], int size);
void reverseArray(int array[], int size);
void reverseSelectedRangeWithinArray(int array[], int size);
int findSequence(int array[], int size);

// Main function
int main(void) {
    int array[SIZE];

    // array function calls with additional header above each output
    puts("*******************************************FillArray (below)***************************************");
    fillArray(array, SIZE);

    puts("*******************************************Find With Range (below)*********************************");
    findWithRange(array, SIZE);

    puts("*******************************************Reverse Array (below)***********************************");
    reverseArray(array, SIZE);

    puts("*******************************************Reverse Array (below)***********************************");
    reverseSelectedRangeWithinArray(array, SIZE);

    puts("*******************************************Find Sequence (below)***********************************");
    findSequence(array, SIZE);
}

// Helper function to easily print out array
void printArray(int array[], int size) {
    for(int i=1; i<=SIZE; ++i) {
        printf("%10d", array[i]);

        // Every 10 elements make a new line
        if(i % 10 == 0) {
            puts("");
        }
    }
}

// Fills a 1D array with random integers. Integers are picked in the range rand_min to rand_max (inclusive)
void fillArray(int array[], int size) {
    // generate a random seed to produce a unique array everytime using the time function
    srand((unsigned)time(NULL));

    // populate array
    for(int i=1; i<=SIZE; ++i) {
        array[i] = rand() % (RAND_MAX+1) + RAND_MIN;
    }

    printArray(array, SIZE);
    puts("");
}

// Locates the largest element in a range of the same array.
void findWithRange(int array[], int size) {
    // populate and print array
    fillArray(array, SIZE);

    int max = 0;
    int lowSelectRange;
    int highSelectRange;

    // Ask user for input
    printf("%s", "Please select low and high range: ");
    scanf("%d %d", &lowSelectRange, &highSelectRange);

    // If ranges are out of bounds, kick user out
    if(highSelectRange < lowSelectRange) {
        puts("High range can't be less then low range, please run again");
        exit(0);
    }

    // find the max element between two points
    for(int i=lowSelectRange+1; i<=highSelectRange; ++i) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    printf("The max between %d and %d is %d\n", lowSelectRange, highSelectRange, max);
}

// Reverses the order of the array elements
void reverseArray(int array[], int size) {
    // Display original array
    puts("Original:");
    fillArray(array, SIZE);

    // Reverse original array
    puts("Reversed");
    for(int lo=0, hi = SIZE+1; lo<hi; lo++, hi--) {
        int temp = array[lo];
        array[lo] = array[hi];
        array[hi] = temp;
    }

    // Print reversed array
    printArray(array, SIZE);
}

// Reverses the order of the array elements in a range between two indexes, startRange and endRange
void reverseSelectedRangeWithinArray(int array[], int size) {
    // Populate and print array
    puts("Original:");
    fillArray(array, SIZE);

    int startrange;
    int endRange;

    // Ask user for range input
    printf("%s", "Please select start and end range: ");
    scanf("%d %d", &startrange, &endRange);

    // If end range is less then start range, kick out user
    if(endRange < startrange) {
        puts("End range can't be less then start range, please run again");
        exit(0);
    }

    // Using user input, reverse just that section of the array
    printf("Reversing between %d and %d\n", startrange, endRange);
    for(int lo=startrange+1, hi=endRange; lo<hi; lo++, hi--) {
        int temp = array[lo];
        array[lo] = array[hi];
        array[hi] = temp;
    }

    // Print newly reversed array
    printArray(array, SIZE);
}

// Looks for two adjacent integers in the array, return index of first element or -1 if sequence isn't present
int findSequence(int array[], int size) {
    int tom;
    int jerry;
    bool found = false;

    // Ask user for input ranges
    printf("Enter two numbers: ");
    scanf("%d %d", &tom, &jerry);

    // If either inputs are out of bounds then kick user out
    if(tom > 100 || tom < 0 || jerry > 100 || jerry < 0) {
        puts("Invalid input");
        exit(0);
    }

    // Populate and output array
    fillArray(array, SIZE);

    // Search the ith and i+1 element to find pair (tom & jerry)
    for(int i=1; i<=SIZE-1; ++i) {
        // If pair is found then print out ith location and return true;
        if(array[i] == tom && array[i+1] == jerry) {
            printf("sequence found at index %d", i);
            found = true;
            return 0;
        }
    }

    // If pair isn't found then return false
    if(found == false) {
        puts("sequence not found");
        return 0;
    }
}
