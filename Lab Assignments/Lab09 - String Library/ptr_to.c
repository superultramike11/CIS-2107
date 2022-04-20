#include "string.h"
#include <stdio.h>

char *ptr_to(char *h, char *n) {
    int i = 0;

    while(h[i] != '\0') {
        if(h[i] == n) {
            return n;
        }
        i++;
    }
    return NULL;
}
