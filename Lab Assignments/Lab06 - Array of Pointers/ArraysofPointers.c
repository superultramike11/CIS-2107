/*
Name: Michael Ewing
Date: 7/3/2022
Course: CSI2107
HW#: Lab 05: ““Arrays of Pointers to Functions”

Objective: To design and implement array of function pointer.

The purpose of this program is to modify existing code related to examslecting
grades for individual students in a 2D matrix and determining the minimum, maximum, and each average.

// Each of the functions has also been modified to allow for a
// menu-driven interface. This interface is an array of pointers to the functions.

*/

#include <stdio.h>
#include <stdlib.h>
#define STUDENTS 3
#define EXAMS 4

void printArray(int a, int grades[][EXAMS], int students, int exams);
void minimum(int b, int grades[][EXAMS], int students, int exams);
void maximum(int c, int students, int exams, int grades[][EXAMS]);
void average(int d, int students, int exams, int grades[][EXAMS]);

int main() {
    void (*f[4])(int) = {printArray, minimum, maximum, average};
    int grades[STUDENTS][EXAMS] = { { 77, 68, 86, 73},
                                    { 96, 87, 89, 78},
                                    { 70, 90, 86, 81} };

    printf("%s", "Enter a choice:\n\t0 Print the array of grades\n\t1 Find the minimum grade\n\t2 Find the maximum grade\n\t3 Print the average on all tests for each student\n\t4 End Program\n\t");
    int choice; // variable to hold user's choice
    scanf("%d", &choice);

    // process user's choice
    while(choice >= 0 && choice < 4) {
        // invoke function at location choice in array f and pass
        // choice as an argument
        (*f[choice])(choice);

        printf("%s", "Enter a choice:\n\t0 Print the array of grades\n\t1 Find the minimum grade\n\t2 Find the maximum grade\n\t3 Print the average on all tests for each student\n\t4 End Program\n\t");
        scanf("%d", &choice);
    }

    puts("Program execution completed");
}

// students are pupils, exams are tests
void printArray(int a, int grades[][EXAMS], int students, int exams){
    puts("Here is your 2Dim array:");
    for(size_t i=0; i<3; ++i) {
        printf("%s", "[");
        for(size_t j=0;j<4; ++j) {
            if(j == exams - 1) {
                printf("%d", grades[i][j]);
            }
            else {
                printf("%d, ", grades[i][j]);
            }
        }
        puts("]");
   }
}

void minimum(int b, int grades[][EXAMS], int students, int exams){
    printf("You entered %d so minimum was called\n\n", b);
}
void maximum(int c, int students, int exams, int grades[][EXAMS]){
    printf("You entered %d so maximum was called\n\n", c);
}
void average(int d, int students, int exams, int grades[][EXAMS]){
    printf("You entered %d so average was called\n\n", d);
}
