#include <stdio.h>
#include "string.h"

char *str_connect(char **strs, int n, char c) {
    for(int i=0; i<n-1; i++) {
        printf("%s", strs[i]);
        if(i<n-2) {
            printf("%c", c);
        }
    }
}
