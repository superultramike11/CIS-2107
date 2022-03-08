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
// Pre-process directives
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);

// Main function
int main() {
    void (*f[4])(int students, int exams, int grades[students][exams]) = {printArray, minimum, maximum, average};
    int students, exams;

    // Ask user for # of rows and cols
    puts("Let's create a 2Dim array for the grades!");
    printf("\tHow many students? ");
    scanf("%d", &students);
    printf("\tHow many exams for each student? ");
    scanf("%d", &exams);

    // Declare array
    int grades[students][exams];

    // Ask user for array elements
    puts("");
    for(size_t i=0; i<students; ++i) {
        for(size_t j=0;j<exams; ++j) {
            printf("\tenter [%d][%d]: ", i, j);
            scanf("%d, ", &grades[i][j]);
        }
    }
    puts("");

    printf("%s", "Enter a choice:\n\t0 Print the array of grades\n\t1 Find the minimum grade\n\t2 Find the maximum grade\n\t3 Print the average on all tests for each student\n\t4 End Program\n\t");
    int choice; // variable to hold user's choice
    scanf("%d", &choice);

    // process user's choice
    while(choice >= 0 && choice < 4) {
        // invoke function at location choice in array f and pass
        // choice as an argument
        (*f[choice])(students, exams, grades);

        printf("%s", "Enter a choice:\n\t0 Print the array of grades\n\t1 Find the minimum grade\n\t2 Find the maximum grade\n\t3 Print the average on all tests for each student\n\t4 End Program\n\t");
        scanf("%d", &choice);
    }

    puts("Program execution completed");
}

// students are pupils, exams are tests
void printArray(int students, int exams, int grades[students][exams]){
    puts("Here is your 2Dim array:");
    printf("# of students is: %d\n", students);
    printf("# of exams is: %d\n", exams);
    for(size_t i=0; i<students; ++i) {
        for(size_t j=0;j<exams; ++j) {
            printf("%d ", grades[i][j]);
        }
    }
}

void minimum(int students, int exams, int grades[students][exams]){
    puts("You entered %d so minimum was called\n\n");
}
void maximum(int students, int exams, int grades[students][exams]){
    puts("You entered %d so maximum was called\n\n");
}
void average(int students, int exams, int grades[students][exams]){
    puts("You entered %d so average was called\n\n");
}
