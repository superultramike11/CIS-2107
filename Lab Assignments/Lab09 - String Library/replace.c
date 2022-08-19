#include "string.h"
#include <stdio.h>

/*
int main() {
    puts("Test for pad");
    char add1[100] = "Steph is the X";
    char word[100] = "X";
    char add2[100] = "best";
    replace(add1, word, add2);
}
*/

char *replace(char *s, char *pat, char *rep) {
    char neww[100];
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

        neww[n++] = s[i];
    }

    neww[n] = '\0';

    printf("Final string: %s%s",neww, rep);

    return neww;
}

