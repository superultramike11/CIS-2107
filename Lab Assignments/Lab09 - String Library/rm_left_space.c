#include "string.h"
#include <stdio.h>

void rm_left_space(char *s) {
    int index=0, i, j;

    while(s[index] == ' ') {
        index++;
    }

    if(index != 0) {
        i = 0;
        while(s[i + index] != '\0') {
            s[i] = s[i + index];
            i++;
        }
        s[i] = '\0';
    }
}
