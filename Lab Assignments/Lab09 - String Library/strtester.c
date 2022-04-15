#include "string.h"
#include <stdio.h>
#include <ctype.h>

int main(void) {
    puts("Test for all_letters");
    char *s = "hello";
    char *s1 = "sir";
    int all_letters_ = all_letters(s);
    if(all_letters_) {
        printf("String:%s\n", s);
        puts("All characters in string were letters\n");
    } else {
        puts("All characters in string were not letters");
    }

    puts("Test for num_in_range");
    int num_in_range_ = num_in_range(s, 'a', 'h');
    printf("The String:%s\n", s);
    printf("The range %c-%c", 'a', 'h');
    printf("%s %d %s\n\n", "There are", num_in_range_, "letters in the range");

    puts("Test for diff");
    int diff_ = diff(s, s1);
    printf("The Strings: %s, %s\n", s, s1);
    printf("%s %d %s\n\n", "The strings differ in", diff_, "ways");

    puts("Test for diff");
    char *small = "Hello World";
    puts("Before:");
    printf("%s\n", small);
    puts("After:");
    shorten(small, 3);

    puts("Test for len_diff");
    int len_diff_ = len_diff(s, s1);
    printf("The Strings: %s, %s\n", s, s1);
    printf("%s %d\n\n", "The strings differ in length by", len_diff_);

    puts("Test for rm_left_space");
    char left[50];
    printf("Enter string: ");
    gets(left);
    printf("\nBefore Left Trim:%s\n", left);
    rm_left_space(left);

    puts("Test for rm_right_space");
    char right[50];
    printf("Enter string: ");
    gets(right);
    printf("\nBefore Right Trim:%s\n", right);
    rm_right_space(right);

    puts("Test for rm_space");
    char space[50];
    printf("Enter a string: ");
    gets(space);
    rm_space(space);
    printf("%s", space);

    return 0;
}
