#include <stdio.h>
#include <string.h>
#include <ctype.h>

void count(char a[], char w[][10], int n, int b[]) {
    for (int i = 0; i < n; i++) b[i] = 0;
    int i = 0;
    char tempWord[100];
    int len = 0;
    while (a[i] != '\0') {
        if (isalpha(a[i])) {
            tempWord[len++] = a[i];
        } else {
            if (len > 0) {
                tempWord[len] = '\0';
                for (int j = 0; j < n; j++) {
                    if (strcmp(tempWord, w[j]) == 0) {
                        b[j]++;
                    }
                }
                len = 0;
            }
        }
        i++;
    }
    if (len > 0) {
        tempWord[len] = '\0';
        for (int j = 0; j < n; j++) {
            if (strcmp(tempWord, w[j]) == 0) {
                b[j]++;
            }
        }
    }
}

int main() {
    char str[200];
    char words[2][10];
    int counts[2];
    int n = 2;
    if (fgets(str, sizeof(str), stdin) != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len-1] == '\n') {
            str[len-1] = '\0';
        }
    }
    int i = 0;
    int found = 0;
    while (str[i] != '\0' && found < 2) {
        while (str[i] != '\0' && !isalpha(str[i])) {
            i++;
        }
        if (str[i] == '\0') break;
        int k = 0;
        while (str[i] != '\0' && isalpha(str[i])) {
            if (k < 9) {
                words[found][k++] = str[i];
            }
            i++;
        }
        words[found][k] = '\0';
        found++;
    }
    count(str, words, n, counts);
    printf("%s:%d %s:%d", words[0], counts[0], words[1], counts[1]);
    return 0;
}