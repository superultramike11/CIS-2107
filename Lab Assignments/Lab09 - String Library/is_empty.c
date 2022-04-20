#include "string.h"
#include <stdio.h>

int main() {
    puts("Test for is_empty");
    char *s = " ";
    int is_empty_ = is_empty(s);
    printf("is_empty value: %d\n", is_empty_);
    if(is_empty == 1) {
        printf("String:%s\n", s);
        puts("String is empty");
    } else puts("String is NOT empty");
}

int is_empty(char *s) {
    for(int i=0; s[i] != '\0'; i++) {
        if(s[i] != ' ' || s[i] != '\t' || s[i] != '\n') {
            return 1;
        }
        else {
            return 0;
        }
    }
    return 0;
}
