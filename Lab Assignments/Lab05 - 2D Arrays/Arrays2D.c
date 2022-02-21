/*
    Name: Michael Ewing
    Date: 2/20/2022
    Course: CIS 2107 Sec 001
    HW #: Lab 05
    Statement of Problem: To design and implement functions to process 2D Arrays
*/
// Pre-process directives
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Defining static variables
static unsigned int rows = 0;
static unsigned int cols = 0;

// Function prototypes
int max(int array[][cols]);
int rowSum(int array[][cols]);
int columnSum(int array[][cols]);
bool isSquare(int array[][cols]);
void displayOutputs(int array[][cols]);

// Main function
int main(void) {
    // Ask user for # of rows and cols
    puts("Let's create a 2Dim array!\n");
    printf("\tHow many rows? ");
    scanf("%d", &rows);
    printf("\tHow many colums? ");
    scanf("%d", &cols);

    // Declare array
    int array[rows][cols];

    // Ask user for array elements
    puts("");
    for(size_t i=0; i<rows; ++i) {
        for(size_t j=0;j<cols; ++j) {
            printf("\tenter [%d][%d]: ", i, j);
            scanf("%d, ", &array[i][j]);
        }
    }
    puts("");

    // Array function calls
    max(array);
    rowSum(array);
    columnSum(array);
    isSquare(array);
    displayOutputs(array);

}

// Returns the maximum value in the 2d array
int max(int array[][cols]) {
    int max = 0;
    for(size_t i=0; i<rows; ++i) {
        for(size_t j=0;j<cols; ++j) {
            if(array[i][j] > max) {
                max = array[i][j];
            }
        }
    }
    printf("Max element is %d\n\n", max);
    return max;
}

// Returns the sum of the elements in Row X of the 2d array
int rowSum(int array[][cols]) {
    int sum=0;
    for(size_t i=0; i<rows; ++i) {
        for(size_t j=0; j<cols; ++j) {
            sum += array[i][j];
        }
        printf("Sum of row %d = %d\n", i+1, sum);
        sum = 0;
    }
    puts("");
    return sum;
}

// Returns the sum of the elements in Column x of the 2d array
int columnSum(int array[][cols]) {
    int sum;
    for(size_t i=0; i<cols; ++i) {
        for(size_t j=0; j<rows; ++j) {
            sum += array[j][i];
        }
        printf("Sum of column %d = %d\n", i+1, sum);
        sum = 0;
    }
    puts("");
    return sum;
}

// Checks if the array is square (every row has the same length as the 2d array itself)
bool isSquare(int array[][cols]) {
    if(rows == cols) {
        puts("This is a square array.\n");
        return true;
    }
    else {
        puts("This is not a square array.\n");
        return false;
    }
}

// Displays the 2 dim-array elements
void displayOutputs(int array[][cols]) {
    puts("Here is your 2Dim array:");
    for(size_t i=0; i<rows; ++i) {
        printf("%s", "[");
        for(size_t j=0;j<cols; ++j) {
            if(j == cols - 1) {
                printf("%d", array[i][j]);
            }
            else {
                printf("%d, ", array[i][j]);
            }
        }
        puts("]");
   }
}
