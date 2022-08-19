#include "string.h"
#include <stdio.h>

void shorten(char *s, int new_len) {
    int len = 0;
    char *t=s;
    while(*t!='\0') {
        t++;
        len++;
    }

    if(new_len > len) {
        printf("%s", s);
        exit(1);
    }

    int i=0;
    while(i!=new_len) {
        printf("%c", *s);
        s++;
        i++;
    }
}
