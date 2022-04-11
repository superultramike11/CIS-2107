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
    puts("Test for upperLower");
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    puts("\n\nTest for convertStrtoInt");
    printf("\tThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    puts("\n\nTest for convertStrtoFloat");
    printf("\tThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    puts("\n\nTest for compareStr");
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    puts("\n\nTest for comparePartialStr");
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    puts("\n\nTest for randomize");
    randomize();

    //test for tokenize number
    puts("\nTest for tokenize number");
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    puts("\n\nTest for reverse");
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    puts("\n\nTest for countSubstr");
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\t# of Substrings %s inside %s: %d", substring, line1, countSubstr(line1, substring));

    //test for countChar
    puts("\n\nTest for countChar");
    char w = 'w';
    printf("\t# of character %c inside %s: %d", w, line1, countChar(line1, w));

    //test for countAlpha
    puts("\n\nTest for countAlpha");
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    puts("\nTest for countWords");
    char countstring[] = "hello world!";
    printf("\tNumber of words in string is: %d", countWords(countstring));

    //test for startsWithB
    puts("\n\nTest for startsWithB");
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    int size = sizeof(series) / sizeof(series[0]);
    startsWithB(series, size);

    //test for endsWithed
    puts("\nTest for endsWithed");
    endsWithed(series, size);
}


// 1.(Displaying Strings in Uppercase and Lowercase)
void * upperLower (const char * s) {
    char upper[100];
    char lower[100];
    for(int i=0; i<strlen(s); i++) {
        upper[i] = toupper(s[i]);
        lower[i] = tolower(s[i]);
    }
    printf("\t%s %s", upper, lower);
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
        printf("\tTest1 < Test2");
    } else if (comp > 0) {
        printf("\tTest1 > Test2");
    } else {
        printf("\tTest1 = Test2");
    }
}

//5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n) {
    int comp = strncmp(s1, s2, n);
    if(comp < 0) {
        printf("\tComparison of first 4 chars: Test1 < Test2");
    } else if(comp > 0) {
        printf("\tComparison of first 4 chars: Test1 > Test2");
    } else {
        printf("\tComparison of first 4 chars: Test1 = Test2");
    }
}

//6.(Random Sentences)
// article noun verb preposition article and noun
void randomize(void) {
    char *article[] = {"the", "a", "one", "some", "any"};
    char *noun[] = {"boy", "girl", "dog", "town", "car"};
    char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[] = {"to", "from", "over", "under", "on"};
    int s1, s2, s3, s4, s5, s6;
    for(int i=0; i<20; i++) {
        s1 = rand() % 5;
        s2 = rand() % 5;
        s3 = rand() % 5;
        s4 = rand() % 5;
        s5 = rand() % 5;
        s6 = rand() % 5;
        char first_to_upper = toupper(article[s1][0]);
        printf("\t%c%s %s %s %s %s %s.\n", first_to_upper, article[s1] + 1, noun[s2], verb[s3], preposition[s4], article[s5], noun[s6]);
    }
}

//7.(Tokenize Telephone Numbers)
// (267) 436-6281
int tokenizeTelNum(char *num) {
    int area;
    long number;
    char *token, *area_code, *three, *four;
    token = strtok(num, "(");
    area_code = strtok(token, ")");
    three = strtok(NULL, "-");
    four = strtok(NULL, "");

    char *seven = malloc(8);
    strcpy(seven, three);
    strcat(seven, four);

    area = atoi(area_code);
    number = atol(seven);

    printf("\t%d %ld", area, number);
}

//8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text) {
    int length = strlen(text);
    for(int i=length-1; i>=0; i--) {
        if(text[i] == ' ') {
            text[i] = '\0';
            printf("\t%s", &(text[i]) + 1);
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
    int alphabet[26];
    char alpha = 'a';
    for(int i=0; i<26; i++) {
        alphabet[i] = countChar(string, alpha) + countChar(string, toupper(alpha));
        printf("\t%c,%c = %d\n", toupper(alpha), alpha, alphabet[i]);
        alpha++;
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

//13.(Strings Starting with "b")
// "bored", "hello", "Brother", "manual", "bothered"
void startsWithB(char *string[], int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<strlen(string[i]); j++) {
            if(string[i][j] == 'B' || string[i][j] == 'b') {
                printf("\t%s starts with b\n", string[i]);
            }
        }
    }
    puts("");
}

//14.(Strings Ending with "ed") // size is # of words in array
// "bored", "hello", "Brother", "manual", "bothered"
// step through this like a 2d array
void endsWithed(char *string[], int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<strlen(string[i]); j++) {
            if(string[i][j]=='e' && string[i][j+1] == 'd') {
                printf("\t%s ends with ed\n", string[i]);
            }
        }
    }
    puts("");
}
