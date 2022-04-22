#include <stdio.h>
#include "string.h"

int main() {
    puts("Test for str_connect");
    char *array_string[] = {"Washington", "Adams", "Jefferson"};
    int n = 4;
    char c = '-';
    str_connect(array_string, n, c);
}

char *str_connect(char **strs, int n, char c) {
    for(int i=0; i<n-1; i++) {
        printf("%s", strs[i]);
        if(i<n-2) {
            printf("%c", c);
        }
    }
}
