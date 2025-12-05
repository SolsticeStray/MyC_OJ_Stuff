#include <stdio.h>
#include <ctype.h>

#define INPUT_LIMIT 1000

int fun(char a[]){
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++){
        if (isdigit(a[i])){
            a[i] = '0';
            count++;
        }
    }
    return count;
}

int main(){
    char a[INPUT_LIMIT];
    gets(a);
    for(int i=0; a[i]!='\0'; i++){
        if(a[i]=='\n'){
            a[i]='\0';
            break;
        }
    }

    printf("%d:", fun(a));

    int idx=0;
    while (a[idx] != '\0'){
        if (a[idx] != '0')  
            printf("%c", a[idx]);
        idx++;
    }

    return 0;
}