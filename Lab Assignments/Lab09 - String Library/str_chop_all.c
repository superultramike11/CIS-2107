#include "string.h"
#include<stdio.h>

char **str_chop_all(char *s, char c) {
    int len=0;

    while(s[len]!='\0') {
        len++;
    }

    for(int i=0; i<len; i++) {
        if(s[i]==c) {
            s[i]='\n';
        }
    }
    puts(s);
}
