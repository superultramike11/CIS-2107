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
        printf("'%c' not found.", n);
    } else printf("'%c' is found at index %d", n, index);

    puts("Test for ptr_to");
    char *ptr_to_Char = 'a';
    char *ptr_to_String = "Star";
    char* ptr = ptr_to(ptr_to_String, ptr_to_Char);
    printf("Pointer returns: %c\n", ptr);

    puts("Test for is_empty");
    char *empty = "Hello";
    int is_empty_ = is_empty(empty);
    printf("is_empty value: %d\n", is_empty_);

    puts("Test for str_zip");
    char *ptr1 = "Temple";
    char *ptr2 = "Hello";
    char* ptr_zip = str_zip(ptr1, ptr2);

    puts("Test for capitalize");
    char capital[50] = "FIX ME CAPITALIZED";
    printf("Original String: %s\n", capital);
	capitalize(capital);

	puts("Test for strcmp_ign_case");
    char strcmp1[50] = "hello";
    char strcmp2[50] = "hello";
    printf("Value returned: %d", strcmp_ign_case(strcmp1, strcmp2));

    puts("Test for strcmp_ign_case");
    char last1[50] = "hello";
    int limit = 3;
    take_last(last1, limit);

    puts("Test for dedup");
    char dedup1[50] = "hello";
    printf("Old String: %s\n", dedup1);
    printf("New string: %s\n", dedup(dedup1));

    puts("Test for pad");
    char pad1[100] = "hello";
    int multi = 6;
    printf("Old String: %s\n", pad1);
    printf("New string: %s\n", pad(pad1, multi));

    puts("Test for ends_with_ignore_case");
    char suff[100] = "ing";
    char sends[100] = "Coding";
    printf("Returns: %d\n", ends_with_ignore_case(sends, suff));

    puts("Test for repeat");
    char str1[100] = "all right", str2[100] = ",";
    int x = 3;
    repeat(str1, x, str2);

    puts("Test for replace");
    char add1[100] = "Steph is the X";
    char word[100] = "X";
    char add2[100] = "best";
    replace(add1, word, add2);

    puts("Test for str_connect");
    char *array_string[] = {"Washington", "Adams", "Jefferson"};
    int num = 4;
    char c = '-';
    str_connect(array_string, n, c);

    puts("Test for empties");
    char *word_empty[] = {"Hello", "World", " ", " ", "Steph"};
    rm_empties(word_empty);

    puts("Test for str_chop_all");
    char arr_chop[50] = "dog is the best";
    char c_chop = '/';
    str_chop_all(arr_chop, c_chop);

    return 0;
}
