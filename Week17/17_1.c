#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {

    char str[100];
    char current[100],longest[100];
    int cur_idx = 0;
    int max_idx = 0;

    fgets(str,100,stdin);

    int len=strlen(str);

    for (int i=0;i<=len;i++) {
        if ( i < len && isalpha(str[i])) {
            current[cur_idx++] = str[i];
        }
        else {
            current[cur_idx] = '\0';
            if (cur_idx > max_idx) {
                max_idx = cur_idx;
                strcpy(longest,current);
            }
            cur_idx = 0;
        }
    }

    printf("%s\n",longest);

    return 0;
}
