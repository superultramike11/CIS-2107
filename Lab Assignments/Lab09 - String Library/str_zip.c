#include "string.h"
#include <stdio.h>

char *str_zip(char *s1, char *s2) {
    int len_s1, len_s2;
    char *ptr = "";
    for(len_s1 = 0; *(s1+len_s1)!= '\0'; len_s1++);
    for(len_s2 = 0; *(s2+len_s2)!= '\0'; len_s2++);

    for(int i=0; i<len_s1; i++) {
        printf("%c", *s1++);
        printf("%c", *s2++);
    }

    return *s1;
}
