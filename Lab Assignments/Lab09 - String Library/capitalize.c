#include "string.h"
#include <stdio.h>
#include <ctype.h>

/*
int main() {
    puts("Test for capitalize");
    char capital[100] = "FIX ME CAPITALIZED";
    printf("Original String: %s\n", capital);
	capitalize(capital);
}
*/

void capitalize(char *str) {
	for(int i=0; str[i]!='\0'; i++) {
		if(i==0) {
			if((str[i]>='a' && str[i]<='z')) {
                str[i]=toupper(str[i]);
			}
			continue;
		}
		if(str[i]==' ') {
			i++;
			if(str[i]>='a' && str[i]<='z') {
				str[i]=toupper(str[i]);
			}
		}
		else {
			if(str[i]>='A' && str[i]<='Z')
				str[i]=tolower(str[i]);
		}
	}

	printf("New String: %s\n",str);
}
