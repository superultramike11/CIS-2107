#include "string.h"
#include <stdio.h>

int is_empty(char *s) {
    while(*s != '\0') {
        if(s[0] == ' ') {
            return 1;
        }
        if(*s != ' ' || *s != '\t' || *s != '\n') {
            return 0;
        }
        s++;
    }
    return 1;
}
