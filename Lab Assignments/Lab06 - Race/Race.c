/*
    Name: Michael Ewing
    Date: 3/14/2022
    Course: CIS 2107 Sec 001
    HW #: Lab 05 Race
    Statement of Problem: To design and implement functions to process pointers
        The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
        generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
        controlled using the sleep() function. Sometimes it takes a while due to slippage.
*/
// Pre-process directives
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Function Prototypes
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos,int tPos);

// Main Function
int main(){
    // Declare random # generator
    //srand((unsigned)time(NULL));

    // Declare T and H position
    int hPos =1;						//hare start position is 1, cannot slip past 1
    int tPos = 1;						//tortoise start position is 1, cannot slip past 1

    // Print Header
    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	//the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");	//the spacing is modeled after the sample

    // Main function calls
    while(hPos != 70 && tPos != 70){
        printf("\t");
        sleep(0.9);						//slows down the race (reduce number to speed up the race 0.9 works well)
        tortMove(&tPos);
        hareMove(&hPos);
        printRace(hPos,tPos);
        puts("");
    }

    // Print the ending conditions based on the last tick
    if(tPos > hPos) {
        printf("\tTORTOISE WIN !!! YAY !!!\n");
    }
    else if(tPos < hPos) {
        printf("\tHARE WIN. Yuch.\n");
    }
    else if(tPos == hPos) {
        printf("\tTORTOISE WIN !!! YAY !!!\n");
    }
    // if neither animal wins, perform the loop again to simulate the next tick of the clock.
}

//Prints the position of the H and T
void printRace(int hPos,int tPos){

    // If T and H are in same position, then print that they collide
    if(tPos == hPos) {
        for(int i = 1; i < tPos; i++){
            printf("%s", "");
        }
        printf("OUCH!!!");
    }

    // if T is behind H, then print the T pos first then the H pos
    else if(tPos < hPos){
        for(int i = 1; i < tPos; i++ ){
            printf("%s", " ");
        }
        printf("T");

        for(int i = 1; i < (hPos - tPos); i++){
            printf("%s", " ");
        }
        printf("H");
    }

    // If H is behind T, then print the H pos first then the H pos
    else {
        for(int i = 1; i < hPos; i++){
            printf("%s", " ");
        }
        printf("H");

        for(int i = 0; i < (tPos - hPos); i++){
            printf("%s", " ");
        }
        printf("T");
    }
}

//Controls the tortoise movement
void tortMove(int *tPtr){
    // Generate random #
    int i = rand() % 10;

    // 1-5 Fast Plod
    if(1 >= 1 && i <= 5) {
        *tPtr += 3; // move 3 to the right
    }
    // 6-7 Slip
    else if(i >= 6 && i <= 7) {
        *tPtr -= 6; // move 6 to the left
    }
    // 8-10 Slow Plod
    else {
        *tPtr += 1; // move 1 to the right
    }

    //stops the race once it reaches 70 ticks
    if(*tPtr < 1) {
        *tPtr = 1;
    }
    else if(*tPtr > 70) {
        *tPtr = 70;
    }
}

//Controls the hare movement
void hareMove(int *hPtr){
    // Generate random #
    int i = rand() % 10;

    // 1-2 Sleep
    if(i >= 1 && i <= 2) {
        *hPtr = *hPtr; // move nowhere
    }
    // 3-4 Big Hop
    else if(i >= 3 && i <= 4) {
        *hPtr += 9; // move 9 to the right
    }
    // 5 Big Slip
    else if(i == 5) {
        *hPtr -=12; // move 12 to the left
    }
    // 6-8 Small Hop
    else if(i >= 6 && i <= 8) {
        *hPtr += 1; // move 1 to the right
    }
    // 9-10 Small Slip
    else {
        *hPtr -= 2; // move 2 to the left
    }
}
