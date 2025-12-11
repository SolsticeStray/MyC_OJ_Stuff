#include <stdio.h>
#include <string.h>

void fun(char xx[]) {

    int len = strlen(xx);

    for (int i=0;i<len; i++) {
        if (xx[i]>='0'&&xx[i]<='9') {
            for (int j=len;j>=i;j--) {
                xx[j+1] = xx[j];
            }
            xx[i]='$';
            len++;
            i++;
        }
    }

}

int main(void) {

    char str[100]={0};
    fgets(str, 100, stdin);

    fun(str);

    int len = strlen(str);

    printf("%s", str);

    return 0;
}