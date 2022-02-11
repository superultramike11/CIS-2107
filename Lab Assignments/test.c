// C program to find diameter, circumference and area of a circle using functions

#include <stdio.h>
#define PI 3.1415

// Your Function prototypes should be listed first*/
float diameter(float radius);
float circumference(float radius);
float area(float radius);

int main() {
    float radius, diameter, circ, area;
    /* Reads radius of the circle from user */

    printf("Enter radius of the circle: ");
    scanf("%f", &radius);

    diameter = diameter(radius);                //Call diameter function
    circ = circumference(radius);               //Call circumference function
    area = area(radius);                        //Call area function

    printf("Diameter of the circle = %.2f units\n", dia);
    printf("Circumference of the circle = %.2f units\n", circ);
    printf("Area of the circle = %.2f sq. units\n", ar);

    return 0;
}

// Your Function implementations should be listed last*/

// diameter function: Find the diameter of a circle whose radius is given. Remember diameter = 2 * Radius
float diameter(float radius) {
    return (2 * radius);
}

// circumference function: Find circumference of the circle whose radius is given. Remember circumference = 2 * PI * Radius
float circumference(float radius) {
    return (2* PI * radius);
}

// area function: Find area of the circle whose radius is given. Remember Area = PI * Radius2
float area(float radius) {
    return (PI * (radius * radius));
}
