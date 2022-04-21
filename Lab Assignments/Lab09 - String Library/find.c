// returns the index of the first occurrence of n in the string h or -1 if it isn't found
#include "string.h"
#include <stdio.h>

int main() {
    puts("Test for find");
    char *n = 'q';
    char *h = "Hello";
    int index = find(h, n);
    if (index == -1) {
        printf("'%c' not found.", n);
    } else printf("'%c' is found at index %d", n, index);
}

int find(char * h, char * n) {
    int i = 0;

    while(h[i] != '\0') {
        if(h[i] == n)
            return i;
        i++;
    }

    return -1;
}
