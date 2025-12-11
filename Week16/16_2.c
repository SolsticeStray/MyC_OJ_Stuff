#include <stdio.h>

#define MAX_INPUT 100

int main(void) {

    char input[MAX_INPUT];
    fgets(input, MAX_INPUT, stdin);

    int trait[26] = {0};

    for (int i=0; input[i]!='\0' && input[i]!='\n';i++) {
        char c = input[i];
        if (c>='A' && c<='Z') {
            c = c -'A'+'a';
        }
        if (c>='a' && c<='z') {
            trait[c-'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (trait[i] > 0) {
            printf("%c:%d ", 'a' + i, trait[i]);
        }
    }
    printf("\n");

    return 0;
}