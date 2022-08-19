#include "string.h"
#include <stdio.h>


char *replace(char *s, char *pat, char *rep) {
    char word[100];
    int i, j = 0, k = 0,n = 0;
    int flag = 0;

    int len1=0;
    while(pat[len1]!='\0') {
        len1++;
    }

    for(i = 0 ; s[i] != '\0' ; i++) {
        k = i;
        while(s[i] == pat[j]) {
            i++,j++;
            if(j == len1) {
                flag = 1;
                break;
            }
        }
        j = 0;

        if(flag == 0)
            i = k;
        else
            flag = 0;

        word[n++] = s[i];
    }

    word[n] = '\0';

    printf("Final string: %s%s",word, rep);

    return word;
}

