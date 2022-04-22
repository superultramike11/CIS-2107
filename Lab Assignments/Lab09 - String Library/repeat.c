#include "string.h"
#include <stdio.h>

/*
int main() {
    puts("Test for repeat");
    char str1[100] = "all right", str2[100] = ",";
    int x = 3;
    repeat(str1, x, str2);
}
*/

char *repeat(char *str1, int x, char *str2) {
    char str3[100];
    int i = 0, j = 0;

    while (str1[i] != '\0') {
        str3[j] = str1[i];
        i++;
        j++;
    }

    i = 0;
    while (str2[i] != '\0') {
        str3[j] = str2[i];
        i++;
        j++;
    }
    str3[j] = '\0';

    for(i=0; i<x; i++) {
        printf("%s", str3);
    }
    puts("");
    return str3;
}
