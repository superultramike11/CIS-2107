#include "string.h"
#include <stdio.h>
#include <ctype.h>

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
