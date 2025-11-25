#include <ctype.h>
#include <stdio.h>
#define MAX_INPUT 999

int* count(char *ch_p) {
    if ('A'<=*ch_p && *ch_p<='Z') {*ch_p=*ch_p-'A'+'a';}
    static int vowels;
    if (*ch_p=='a'||*ch_p=='e'||*ch_p=='i'||*ch_p=='o'||*ch_p=='u') {
        vowels++;
    }
    return &vowels;
}

int main(void) {
    char input[MAX_INPUT];
    int temp = 0;
    gets(input);
    for (char *p=input; *p!='\0'; p++) {
        if (isalpha(*p)) {
            temp = *count(p);
        }
    }
    printf("%s,%d\n",input,temp);
    return 0;
}