#include "string.h"
#include <stdio.h>

int main() {
    puts("Test for ends_with_ignore_case");
    char suff[100] = "ing";
    char sends[100] = "Coding";
    printf("Returns: %d\n", ends_with_ignore_case(sends, suff));
}

int ends_with_ignore_case(char *s, char *suff) {
    int len1=0,len2=0;
    while(s[len1]!='\0') {
        len1++;
    }
    while(suff[len2]!='\0') {
        len2++;
    }

    char *p1, *p2, *p3;
    int j=0,flag=0;

    p1 = s;
    p2 = suff;

    for(int i = 0; i<len1; i++) {
        if(*p1 == *p2) {
            p3 = p1;
            for(j = 0;j<len2;j++) {
                if(*p3 == *p2) {
                    p3++;p2++;
                }
                else break;
            }
            p2 = suff;
            if(j == len2) {
                flag = 1;
                return 1;
            }
        }
        p1++;
    }
    if(flag==0) {
        return 0;
    }
}
