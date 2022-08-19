#include <stdio.h>
#include "string.h"

void rm_empties(char **words) {
    int len1 = 0;
    while(words[len1] != '\0') {
        len1++;
    }

    for(int i=0; i<len1; i++) {
        if(words[i] != " ") {
            printf("%s ", words[i]);
        }
    }
}
