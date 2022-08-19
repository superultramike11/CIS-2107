#include "string.h"
#include <stdio.h>
#include <ctype.h>

/*
int main() {
    puts("Test for dedup");
    char dedup1[100] = "hello";
    printf("Old String: %s\n", dedup1);
    printf("New string: %s\n", dedup(dedup1));
}
*/

char *dedup(char *s) {
    char *ptr = s;

    int len1=0;
    while(s[len1]!='\0') {
        len1++;
    }

    for(int i = 0; i < len1; i++) {
  		for(int j = i + 1; ptr[j] != '\0'; j++) {
  			if(ptr[j] == ptr[i]) {
  				for(int k = j; ptr[k] != '\0'; k++) {
					ptr[k] = ptr[k + 1];
				}
 			}
		}
	}
    return ptr;
}
