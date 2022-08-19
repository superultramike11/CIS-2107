#include <stdio.h>

int main() {
    float seasons[] = {1,2,3,4};
    printf("size of seasons = %lu\n", sizeof(seasons));
    printf("size of seasons 0 = %lu\n", sizeof(seasons[0]));
    printf("Long = %lu\n", sizeof(seasons)/sizeof(seasons[0]));
}
