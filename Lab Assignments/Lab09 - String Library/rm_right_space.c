#include "string.h"
#include <stdio.h>

void rm_right_space(char *s) {
    int index = 0, i = 0, j;
    while(s[index] == ' ') {
        index++;
    }
    if(index != 0) {
        while(s[i + index] != '\0') {
            s[i] = s[i + index];
            i++;
        }
        s[i] = '\0';
    }
    printf("\After Right Trim:%s\n", s);
}
