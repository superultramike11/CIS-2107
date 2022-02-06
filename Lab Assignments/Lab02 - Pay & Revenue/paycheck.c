/*
    Name: Michael Ewing
    Date: 1/26/2022
    Course: CIS 2107 Sec 001
    HW #: Lab 02
    Statement of Problem: Write a C program called paycheck to calculate the paycheck for a Temple employee based on the hourlySalary, weeklyTime
                          (working for maximum 40 hours) and overtime (working for more than 40 hours).
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n\n");

    double hourlySalary;
    double weeklyTime;
    double overtime;
    double overtimehours;
    double regularpay;
    double netpay;
    double employeenum, fractpart, intpart;

    // Asking user for input
    printf("\tEnter Employee Number: ");
    scanf("%lf", &employeenum);
    fractpart = modf(employeenum, &intpart);
    // if the user inputs less an ID less then 0 (zero) or an ID with a decimal point, it exits out
    if(employeenum < 0 || fractpart > 0) {
        printf("\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n\n");
        printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n\n");
        exit(0);
    }

    printf("\tEnter Hourly Salary: ");
    scanf("%lf", &hourlySalary);
    // if the user inputs a negative salary, it exits out
    if(hourlySalary < 0) {
        printf("\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n\n");
        exit(0);
    }

    printf("\tEnter Weekly Time: ");
    scanf("%lf", &weeklyTime);
    // if the user inputs a negative time, it exits out
    if(weeklyTime < 0) {
        printf("\n\tThis is not a weekly time.\n\tPlease run the program again\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n\n");
        exit(0);
    }

    printf("\t==============================\n");

    // Calculating and presenting information
    printf("\tEmployee #: %.0lf\n", employeenum);
    printf("\tHourly Salary: $%.1lf\n", hourlySalary);
    printf("\tWeekly Time: %.1lf\n", weeklyTime);

    // If the employee works for 40 hours and less, then there is no overtime, and the NetPay = weekly time * hourly salary.
    if(weeklyTime <= 40) {
        regularpay = weeklyTime * hourlySalary;
        printf("\tRegular Pay: $%.1lf\n", regularpay);
        printf("\tOvertime Pay: $%.1lf\n", overtime);
        printf("\tNet Pay: $%.1lf\n", regularpay);
    }

    // If the employee works for more than 40 hours, let’s say 50 hours, then her
    //        NetPay = 40 hours*regularPay + 10 hours* overtime. OR
    //        NetPay = 40 hours*regularPay + 10 hours* (1.5 * regular pay).
    // overtime = 1.5 * regular pay
    if(weeklyTime > 40) {
        regularpay = 40 * hourlySalary;
        overtimehours = weeklyTime - 40;
        overtime = 1.5 * hourlySalary;
        netpay = (40 * hourlySalary) + (overtimehours*overtime);
        printf("\tRegular Pay: $%.1lf\n", regularpay);
        printf("\tOvertime Pay: $%.1lf\n", (netpay-regularpay));
        printf("\tNet Pay: $%.1lf\n", netpay);
    }
    printf("\t==============================\n");

    printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n\n");
}
