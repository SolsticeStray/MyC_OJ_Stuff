#include <stdio.h>
#define MAX_ARRAY_SIZE 10

int main(void) {
    int i=0;
    int array[MAX_ARRAY_SIZE];
    for (;i<MAX_ARRAY_SIZE;i++) {
        scanf("%d",&array[i]);
    }
    for (i=0;i<MAX_ARRAY_SIZE;i++) {
        for (int j=i+1;j<MAX_ARRAY_SIZE;j++) {
                if (array[i]==array[j]) {array[j]=-1;}
            }
        }
    int count=0;
    for (i=0;i<MAX_ARRAY_SIZE;i++) {
        if (array[i]==-1) {count++;}
    }
    printf("%d\n",MAX_ARRAY_SIZE-count);
    return 0;
}