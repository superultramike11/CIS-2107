#include "string.h"
#include <stdio.h>

int len_diff(char *s1, char *s2) {
    char *t1 = s1, *t2 = s2;

    while(*t1!='\0') {
        t1++;
    }
    //printf("Length1 = %d\n", t1-s1);

    while(*t2!='\0') {
        t2++;
    }
    //printf("Length2 = %d\n", t2-s2);
    return (t1-s1) - (t2-s2);
}
