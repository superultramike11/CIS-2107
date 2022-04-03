/*
 * Name:	Michael Ewing
 * Section:	01
 * Lab:  	CIS2107_Lab08_Manual
 * Goal: 	To design and implement functions taking pointers as arguments
			to process characters and strings.
 */
#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[], int size);
void endsWithed(char *string[], int size);

int main() {
    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    int size = sizeof(series) / sizeof(series[0]);
    //startsWithB(series, size);

    //test for endsWithed
    endsWithed(series, size);
}


// 1.(Displaying Strings in Uppercase and Lowercase)
void * upperLower (const char * s) {
    while(*s != '\0') {
        printf("%c", toupper(*s++));
    }
}

// 2.(Converting Strings to Integers for Calculations)
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    return atoi(s1) + atoi(s2) + atoi(s3) + atoi(s4);
}

//3.(Converting Strings to Floating Point for Calculations)
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    return atof(s1) + atof(s2) + atof(s3) + atof(s4);
}

//4.(Comparing Strings)
void compareStr(const char *s1, const char *s2) {
    int comp = strcmp(s1, s2);
    if(comp < 0) {
        puts("\nTest1 < Test2");
    } else if (comp > 0) {
        puts("\nTest1 > Test2");
    } else {
        puts("\nTest1 = Test2");
    }
}

//5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n) {
    int comp = strncmp(s1, s2, n);
    if(comp < 0) {
        puts("\nComparison of first 4 chars: Test1 < Test2");
    } else if(comp > 0) {
        puts("\nComparison of first 4 chars: Test1 > Test2");
    } else {
        puts("\nComparison of first 4 chars: Test1 = Test2");
    }
}

//6.(Random Sentences)
void randomize(void) {


}

//7.(Tokenizing Telephone Numbers)
int tokenizeTelNum(char *num) {

    return 0;
}

//8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text) {
    int length = strlen(text);
    for(int i=length-1; i>=0; i--) {
        if(text[i] == ' ') {
            text[i] = '\0';
            printf("%s", &(text[i]) + 1);
        }
    }
    printf(" %s", text);
}

//9.(Counting the Occurrences of a Substring)
int countSubstr (char * line, char * sub) {
    int count = 0;
    while((line=strstr(line, sub)) != NULL) {
        count++;
        line++;
    }
    return count;
}

//10.(Counting the Occurrences of a Character)
int countChar (char *line, char c) {
    int count = 0;
    while((line=strchr(line, c)) != NULL) {
        count++;
        line++;
    }
    return count;
}

//11.(Counting the Letters of the Alphabet in a String)
void countAlpha(char *string) {
    int count = 0;
    int n = strlen(string);
    for(int i=0; i<n; i++) {
        count=1;
        if(string[i]) {
            for(int j=i+1; j<n; j++) {
                if(string[i] == string[j]) {
                    count++;
                    string[j] = '\0';
                }
            }
            printf(" '%c' = %d \n", string[i], count);
        }
    }
}

//12.(Counting the Number of Words in a String)
int countWords(char *string) {
    int count = 0;
    while((string = strtok(string, " "))) {
        string = NULL;
        count++;
    }
    return count;
}

/*
//13.(Strings Starting with "b")
void startsWithB(char *string[], int size) {
    int i,j = 0;
    char ch = 'b';
    while(string[i] != '\0') {
        if((i==0) && string[i]==ch) {
            j=i;
            while(string[j]!=' ') {
                printf("%c", string[j]);
                j++;
            }
            printf(",");
        }
        if((string[i]==' ') && (string[i+1]==ch)) {
            j=i+1;
            while(string[j]!=' '&&j<size) {
                printf("%c", string[j]);
                j++;
            }
            printf(",");
        }

        i++;
    }
}
*/

//14.(Strings Ending with "ed") // size is # of words in array
// step through this like a 2d array
void endsWithed(char *string[], int size) {
    int len = strlen(string);
    for (int i = 0; i<size; i++ ) {
        if(size > 0 && string[i][len-1] == 'd' && string[i][len-2] == 'e') {
            printf("\n%s", string[i]);
        }
    }
}
