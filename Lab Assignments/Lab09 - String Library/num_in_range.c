#include "string.h"
#include <stdio.h>

int num_in_range(char *s1, char b, char t) {
    int count = 0;
    //printf("%c = %d\n", b, b);
    //printf("%c = %d\n", t, t);
    while(*s1!='\0') {
        if(*s1 >= b && *s1 <= t) {
            count++;
        }
        s1++;
    }
    return count;
}
