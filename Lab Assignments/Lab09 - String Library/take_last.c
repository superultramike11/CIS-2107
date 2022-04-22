#include "string.h"
#include <stdio.h>
#include <ctype.h>

/*
int main() {
    puts("Test for strcmp_ign_case");
    char last1[100] = "hello";
    int limit = 3;
    take_last(last1, limit);
}
*/

void take_last(char *s, int n) {
    int len1=0;
    while(s[len1]!='\0') {
        len1++;
    }

    if(n > len1) {
        printf("%s\n", s);
    }

    for(int i=n-1; s[i]!='\0'; i++) {
        printf("%c", s[i]);
    }
    puts("");
}
