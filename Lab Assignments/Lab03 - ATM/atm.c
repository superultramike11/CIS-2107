/*
    Name: Michael Ewing
    Date: 2/03/2022
    Course: CIS 2107 Sec 001
    HW #: Lab 03
    Statement of Problem: Write a C Program for an ATM machine
                          The types of ATM Transaction are:
                          1: Balance  2: Cash Withdrawal  3: Cash deposition  4: Quit
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define PIN 3014

// Function prototypes
int mainmenu(int balance, int transaction);
void displayBalance(int balance, int transaction);
int withdrawal(int balance, int transaction);
int deposit(int balance, int transaction);

// Sign in page to verify user PIN
int main(void) {
    unsigned int balance = 5000;
    unsigned int transactions = 0;
    unsigned int enteredPIN;
    int counter = 0;

    // User input of PIN
    puts("Please login into ATM using your PIN (after 3 failed attempts you will be exited out)");
    printf("\tEnter PIN: ");
    scanf("%d", &enteredPIN);

    // If user input fails, keep asking until correct input is received
    while(enteredPIN != PIN) {
        ++counter;
        scanf("%d", &enteredPIN);
        if(counter == 2) {
            puts("You lost\n");
            puts("**********************************************************************");
            exit(0);
        }
    }

    // If user input is correct, move to the main menu
    if(enteredPIN == PIN) {
        puts("**********************************************************************");
        mainmenu(balance, transactions);
    }
}

// Main menu where all actions are available
int mainmenu(int balance, int transactions) {
    unsigned int action;

    // Ask user for main menu selection
    puts("Welcome to the ATM");
    puts("What transaction would you like to make?");
    puts("\t1: Balance \n\t2: Cash Widthdrawal \n\t3: Cash Deposition \n\t4: Quit");
    puts("ATM will close if 1-4 is not chosen");
    printf("\tEnter ACTION: ");
    scanf("%d", &action);

    puts("**********************************************************************");

    // If user inputs '1' display the balance
    if(action == 1) {
        displayBalance(balance, transactions);
    }

    // If user inputs '2' runs the withdrawal function
    if(action == 2) {
        withdrawal(balance, transactions);
    }

    // If user inputs '3' runs the deposit function
    if(action == 3) {
        deposit(balance, transactions);
    }

    // If user inputs '4' quits program and display # of transactions
    if(action == 4) {
        puts("Thanks for using the ATM, Goodbye!");
        printf("\tNumber of transactions made: %d\n", transactions);
        puts("**********************************************************************");
        exit(0);
    }
}

// Display balance function
void displayBalance(int balance, int transactions) {
    // Prints out customer balance
    printf("\tDear Customer #%d your account balance is $%d\n", PIN, balance);
    puts("**********************************************************************");

    // include this to cycle back to the main menu once function operation is done
    mainmenu(balance, transactions);
}

// Withdrawal function
int withdrawal(int balance, int transactions) {
    double withdrawalAmount;
    unsigned int action;
    double fractpart, intpart;

    // Ask user for withdrawal amount
    puts("How much would you like to withdrawal?");
    puts("Cash Withdrawal Conditions! -> MUST not Exceed 1000 and MUST be a multiple of 20");
    printf("Your current balance amount is: $%d\n", balance);
    printf("\tEnter WITHDRAW AMOUNT: ");
    scanf("%lf", &withdrawalAmount);

    // If withdrawal amount matches these conditions, asks user until correct input
    fractpart = modf(withdrawalAmount, &intpart);
    while(withdrawalAmount > 1000 || fractpart > 0 || withdrawalAmount > balance || (int)withdrawalAmount % 20 != 0) {
        puts("Invalid deposit amount");
        printf("\tEnter WITHDRAWAL AMOUNT: ");
        scanf("%lf", &withdrawalAmount);
        fractpart = modf(withdrawalAmount, &intpart);
    }

    // Update balance and transactions
    balance -= withdrawalAmount;
    transactions++;

    // Ask user if they want a receipt
    printf("Would you like a receipt? (1 for Yes, and 2 for No)\n");
    printf("\tEnter choice: ");
    scanf("%d", &action);

    // If user input is '1' or YES then print out a receipt (if this atm were ACTUALLY used)
    if(action == 1) {
        /*
        printf("\tYou just withdrawn $%d\n", withdrawalAmount);
        printf("\tYour new balance is $%d\n", balance);
        printf("\tYour number of transactions: %d\n\n", transactions);
        */
        puts("Printing receipt now");
        puts("**********************************************************************");
        // include this to cycle back to the main menu once function operation is done
        mainmenu(balance, transactions);

        return balance, transactions;
    }

    // If user input is '1' or NO then go back to main menu
    if(action == 2) {
        puts("**********************************************************************");
        // include this to cycle back to the main menu once function operation is done
        mainmenu(balance, transactions);

        return balance, transactions;
    }
    else {
        puts("Incorrect input, exiting ATM now");
        exit(0);
    }
}

// Deposit function
int deposit(int balance, int transactions) {
    double depositAmount, fractpart, intpart;
    unsigned int action;

    // Ask user for deposit amount
    puts("How much would you like to deposit? (daily limit is $10,000)");
    printf("Your current balance amount is: $%d\n", balance);
    printf("\tEnter DESPOSIT AMOUNT: ");
    scanf("%lf", &depositAmount);

    // If deposit amount matches these conditions, asks user until correct input
    fractpart = modf(depositAmount, &intpart);
    while(depositAmount > 10000 || depositAmount < 0 || fractpart > 0) {
        puts("Invalid deposit amount");
        printf("\tEnter DESPOSIT AMOUNT: ");
        scanf("%lf", &depositAmount);
        fractpart = modf(depositAmount, &intpart);
    }

    // Update balance and transactions
    balance += depositAmount;
    transactions++;

    // Ask user if they want a receipt
    printf("Would you like a receipt? (1 for Yes, and 2 for No)\n");
    printf("\tEnter choice: ");
    scanf("%d", &action);

    // If user input is '1' or YES then print out a receipt (if this atm were ACTUALLY used)
    if(action == 1) {
        /*
        printf("\tYou just deposited $%d\n", depositAmount);
        printf("\tYour new balance is $%d\n", balance);
        printf("\tYour number of transactions: %d\n\n", transactions);
        */
        puts("Printing receipt now");
        puts("**********************************************************************");
        mainmenu(balance, transactions);

        return balance, transactions;
    }

    // If user input is '1' or NO then go back to main menu
    if(action == 2) {
        puts("**********************************************************************");
        // include this to cycle back to the main menu once function operation is done
        mainmenu(balance, transactions);

        return balance, transactions;
    }

    // If user doesn't have correct input then program exits
    else {
        puts("Incorrect input, exiting ATM now");
        exit(0);
    }
}
