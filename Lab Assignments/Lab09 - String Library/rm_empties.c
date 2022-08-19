#include <stdio.h>
#include "string.h"

int main() {
    puts("Test for empties");
    char *word[] = {"Hello", "World", " ", " ", "Steph"};
    rm_empties(word);
}

void rm_empties(char **words) {
    for(int i=0; i<6; i++) {
        if(words[i] != " ") {
            printf("%s ", words[i]);
        }
    }
}
