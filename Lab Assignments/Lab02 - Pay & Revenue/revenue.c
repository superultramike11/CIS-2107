/*
    Name: Michael Ewing
    Date: 1/29/2022
    Course: CIS 2107 Sec 001
    HW #: Lab 02
    Statement of Problem: Write a C program called revenue to calculate the revenue from a sale
                          based on the unit price and quantity of a product input by the user
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    printf("Welcome to \"Temple\" store\n\n");

    double itemprice;
    double quantity;
    double cost;
    double discount;
    double total;
    double fractpart, intpart;

    // Asking user for input
    printf("\tEnter item price: ");
    scanf("%lf", &itemprice);
    fractpart = modf(itemprice, &intpart);
    // if the user inputs less an ID less then 0 (zero) or an ID with a decimal point, it exits out
    if(itemprice < 0) {
        printf("\t\n\tThis is not a valid item price.\n\tPlease run the program again\n\n");
        printf("Thank You for using \"Temple\" store\n\n");
        exit(0);
    }

    printf("\tEnter quantity: ");
    scanf("%lf", &quantity);
    fractpart = modf(quantity, &intpart);
    // if the user inputs a negative salary, it exits out
    if(quantity < 0 || fractpart > 0) {
        printf("\t\n\tThis is not a valid quantity order.\n\tPlease run the program again\n\n");
        printf("Thank You for using \"Temple\" store\n\n");
        exit(0);
    }

    printf("\n");

    // Calculating and presenting information
    printf("\tThe item price is: $%.1lf\n", itemprice);
    printf("\tThe order is: %.0lf item(s)\n", quantity);

    cost = itemprice * quantity;
    printf("\tThe cost is: $%.1lf\n", cost);

    // If the quantity is between a certain range then a specific discount is offered
    if(quantity >= 1 && quantity <= 49) {
        discount = 0;
    }
    else if(quantity >= 50 && quantity <= 99) {
        discount = 0.1;
    }
    else if(quantity >= 100 && quantity <= 149) {
        discount = 0.15;
    }
    else if(quantity >= 150) {
        discount = 0.25;
    }
    // Display discount
    printf("\tThe discount is: %.1lf%%\n", (discount * 100));

    printf("\tThe discount amount is: $%.1lf\n", (discount*cost));

    // Calculate and Display discount
    total = cost - (discount*cost);
    printf("\tThe total is: $%.1lf\n\n", total);

    printf("Thank You for using \"Temple\" store\n\n");
}
