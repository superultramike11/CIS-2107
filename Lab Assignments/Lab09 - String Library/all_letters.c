#include "string.h"

int all_letters(char *s) {
    char *t=s;
    while(*t!='\0') {
        if(*t >= 48 && *t <= 57) {
            return 0;
        }
        t++;
    }
    return 1;
}
