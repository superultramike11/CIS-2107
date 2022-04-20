// returns the index of the first occurrence of n in the string h or -1 if it isn't found
#include "string.h"
#include <stdio.h>

int find(char * h, char * n) {
    int i = 0;

    while(h[i] != '\0') {
        if(h[i] == n)
            return i;
        i++;
    }

    return -1;
}
