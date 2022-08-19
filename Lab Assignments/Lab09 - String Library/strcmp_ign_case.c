#include "string.h"
#include <stdio.h>
#include <ctype.h>

int strcmp_ign_case(char *s1, char *s2) {
    int i, len1=0,len2=0;
    while(s1[len1]!='\0') {
        s1[len1] = tolower(s1[len1]);
        len1++;
    }
    printf("%s has length of %d\n", s1, len1);

    while(s2[len2]!='\0') {
        s2[len2] = tolower(s2[len2]);
        len2++;
    }
    printf("%s has length of %d\n", s2, len2);

    int max = 0;
    if(len1 > len2) {
        max = len1;
    } else max = len2;
    printf("Max is %d\n", max);

    for(i=0; i<max; i++) {
        if(s1[i] < s2[i]) {
            return 1;
            //printf("%c is greater then %c\n", s1[i], s2[i]);
        }
        if(s1[i] > s2[i]) {
            return -1;
        }
    }

    return 0;
}
