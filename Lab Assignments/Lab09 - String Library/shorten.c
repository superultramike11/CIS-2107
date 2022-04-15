#include "string.h"
#include <stdio.h>

// Shortens the string s to new_len.
// If the original length of s is less than or equal to new_len, s is unchanged
void shorten(char *s, int new_len) {
    // Calc the length of the string
    int len = 0;
    char *t=s;
    while(*t!='\0') {
        t++;
        len++;
    }

    // If the new length asks for too much then print and exit
    if(new_len > len) {
        printf("%s", s);
        exit(1);
    }

    // otherwise just print up to the required amount
    int i=0;
    while(i!=new_len) {
        printf("%c", *s);
        s++;
        i++;
    }
}
