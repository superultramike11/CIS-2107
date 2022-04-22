#include <stdio.h>
#include <string.h>
char* magic();
int main() {
    char *ptr;
    ptr = magic();
    printf("%s\n", ptr);
    return 0;
}

char *magic() {
    char disk[30];
    strcpy(disk, "memory in C");
    return (disk);
}
