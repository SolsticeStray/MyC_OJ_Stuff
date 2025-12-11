#include <stdio.h>
#include <string.h>

int isVowel(char ch) {
    char vowels[] = "aeiouAEIOU";
    for (int i = 0; vowels[i] != '\0'; i++) {
        if (ch == vowels[i]) {
            return 1;
        }
    }
    return 0;
}

int hasVowels(char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (isVowel(word[i])) {
            return 1;
        }
    }
    return 0;
}

int FindNoVowel(char *str[],int num,int res[][20]) {

    int count = 0;

    for (int i=0;i<num;i++) {
        if (!hasVowels(str[i])) {
            strcpy(res[count], str[i]);
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(res[i], res[j]) > 0) {
                char temp[20];
                strcpy(temp, res[i]);
                strcpy(res[i], res[j]);
                strcpy(res[j], temp);
            }
        }
    }

    return count;
}

int main(void) {

    char str[10][20];
    char* str_ptr[10];
    for (int i = 0; i < 10; i++) {
        scanf("%s", str[i]);
        str_ptr[i] = str[i];
    }
    int res[10][20];
    int count=FindNoVowel(str_ptr,10,res);

    for (int i = 0; i < count; i++) {
        printf("%s ",res[i]);
    }

    return 0;
}