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

void printArray(int a, int students, int exams, int grades[students][exams]);
void minimum(int b, int students, int exams, int grades[students][exams]);
void maximum(int c, int students, int exams, int grades[students][exams]);
void average(int d, int students, int exams, int grades[students][exams]);

int main()
{
    void (*f[4])(int) = {printArray, minimum, maximum, average};

    printf("%s", "Enter a number betwen 0 and 2, 3 to end: ");
    int choice; // variable to hold user's choice
    scanf("%d", &choice);

    printf("Value of choice: %d\n", choice);
    // process user's choice
    while(choice >= 0 && choice < 4) {
        // invoke function at location choice in array f and pass
        // choice as an argument
        printf("RAN\n");
        (*f[choice])(choice);

        printf("%s", "Enter a number between 0 and 2, 3 to end: ");
        scanf("%d", &choice);
    }

    puts("Program execution completed");
}

void printArray(int a, int students, int exams, int grades[students][exams]){
    printf("You entered %d so printArray was called\n\n", a);
}
void minimum(int b, int students, int exams, int grades[students][exams]){
    printf("You entered %d so minimum was called\n\n", b);
}
void maximum(int c, int students, int exams, int grades[students][exams]){
    printf("You entered %d so maximum was called\n\n", c);
}
void average(int d, int students, int exams, int grades[students][exams]){
    printf("You entered %d so average was called\n\n", d);
}
