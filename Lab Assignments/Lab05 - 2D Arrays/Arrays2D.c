/*
    Name: Michael Ewing
    Date: 2/03/2022
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

static int rows = 0;
static int cols = 0;

int max(int array[][cols]);
int rowSum(int array[][cols]);
int columnSum(int array[][cols]);
bool isSquare(int array[][cols]);
void displayOutputs(int array[][cols]);

int main(void) {


    puts("Let's create a 2Dim array!\n");

    printf("\tHow many rows? ");
    scanf("%d", &rows);

    printf("\tHow many colums? ");
    scanf("%d", &cols);

    int array[rows][cols];

    puts("");

    for(int i=0; i<rows; i++) {
        for(int j=0;j<cols;j++) {
            printf("\tenter [%d][%d]: ", i, j);
            scanf("%d, ", &array[i][j]);
        }
    }
    puts("");

    isSquare(array);

    displayOutputs(array);

    max(array);
}

// Returns the maximum value in the 2d array
int max(int array[][cols]) {
    int max = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0;j<cols;j++) {
            if(array[i][j] > max) {
                max = array[i][j];
            }
        }
    }
    printf("Max element is %d\n", max);
    return max;
}

// Returns the sum of the elements in Row X of the 2d array
int rowSum(int array[][cols]) {

}

// Returns the sum of the elements in Column x of the 2d array
int columnSum(int array[][cols]) {

}

// Checks if the array is square (every row has the same length as the 2d array itself)
bool isSquare(int array[][cols]) {
    if(rows == cols) {
        puts("This is a square array.");
        return true;
    }
    else {
        puts("This is not a square array");
        return false;
    }
}

// Displays the 2 dim-array elements
void displayOutputs(int array[][cols]) {
    puts("Printing 2D Array");
    for(int i=0; i<rows; i++) {
        for(int j=0;j<cols;j++) {
            printf("%d ", array[i][j]);
        }
        puts("");
   }
}
