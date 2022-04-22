#include "string.h"
#include <stdio.h>

int main() {
    puts("Test for rm_left_space");
    char right[] = "Hello      ";
    printf("Before Remove Left Space:%s\n", right);
    rm_right_space(right);
}

void rm_right_space(char *s) {
    int index = 0, i = 0, j;
    while(s[index] == ' ') {
        index++;
    }
    if(index != 0) {
        while(s[i + index] != '\0') {
            s[i] = s[i + index];
            i++;
        }
        s[i] = '\0';
    }
    printf("\After Right Trim:%s\n", s);
}
