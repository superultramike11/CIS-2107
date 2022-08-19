#include <stdio.h>
int main() {
    unsigned char x=0x31;
    printf("~x=0x%x\n", ~x);
    printf("~~x=0x%x\n", ~~x);

    printf("!x=0x%x\n", !x);
    printf("!!x=0x%x\n", !!x);
}
