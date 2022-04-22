#include "string.h"
#include<stdio.h>
#include<stdlib.h>

/*
int main() {
    puts("Test for str_chop_all");
    char arr_chop[50] = "dog is the best";
    char c_chop = '/';
    str_chop_all(arr_chop, c_chop);

    return 0;
}
*/

char **str_chop_all(char *s, char c) {
    int len=0;

    printf("Enter string: ");
    gets(s);

    len = strlen(s);

    for(int i=0; i<len; i++) {
        if(s[i]==c) {
            s[i]='\n';
        }
    }
    puts(s);
}
