#include "string.h"
#include <stdio.h>

void rm_space(char *s) {
    int i=0, j=0;
    while(s[i]) {
        if(s[i] != ' ') {
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';
    return s;
}
