#include "string.h"
#include <stdio.h>

int main() {
    puts("Test for pad");
    char pad1[100] = "hello";
    int multi = 6;
    printf("Old String: %s\n", pad1);
    printf("New string: %s\n", pad(pad1, multi));
}

char *pad(char *s, int d) {
    int len1=0;
    while(s[len1] != '\0') {
        len1++;
    }

    int diff = d - len1;

    printf("New String: %s", s);
    for(int j=0; j<diff; j++) {
        printf(" ");
    }
}
