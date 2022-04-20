#include <stdio.h>
#include "string.h"

int main(void) {
    puts("Test for all_letters");
    char *s = "hello";
    char *s1 = "sir";
    int all_letters_ = all_letters(s);
    if(all_letters_) {
        printf("String:%s\n", s);
        puts("All characters in string were letters\n");
    } else puts("All characters in string were not letters");

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
    char left[] = "    Hello";
    printf("Before Remove Left Space:%s\n", left);
    rm_left_space(left);

    puts("Test for rm_left_space");
    char right[] = "Hello      ";
    printf("Before Remove Left Space:%s\n", right);
    rm_right_space(right);

    puts("Test for rm_space");
    char space[] = "Hello World";
    printf("Before remove all spaces:%s\n", space);
    rm_space(space);
    printf("After remove all spaces:%s\n", space);

    puts("Test for find");
    char *n = 'a';
    char *h = "Star";
    int index = find(h, n);
    if (index == -1) {
        printf("'%c' not found.", find);
    } else printf("'%c' is found at index %d", n, index);

    puts("Test for ptr_to");
    char *ptr_to_Char = 'a';
    char *ptr_to_String = "Star";
    char* ptr = ptr_to(ptr_to_String, ptr_to_Char);
    printf("Pointer returns: %c\n", ptr);

    return 0;
}
