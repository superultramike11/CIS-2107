#include "string.h"
#include <stdio.h>

char *pad(char *s, int d) {
    int len1=0;
    while(s[len1] != '\0') {
        len1++;
    }

    int diff = d - len1;

    printf("New String: %s", s);
    for(int j=0; j<diff; j++) {
        printf(" ");
    }
}
