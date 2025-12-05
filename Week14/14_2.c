#include <stdio.h>
#define MAX_ARRAY_SIZE 10

int main(void) {
    int i,array[MAX_ARRAY_SIZE];
    for (i=0;i<MAX_ARRAY_SIZE;i++) {
        scanf("%d",&array[i]);
    }
    int ans[MAX_ARRAY_SIZE];
    for (i=0;i<MAX_ARRAY_SIZE;i++) {
        for (int j=i+1;j<MAX_ARRAY_SIZE;j++) {
            if (array[i]==array[j]) {array[j]=-1;}
        }
    }
    int index=0;
    for (i=0;i<MAX_ARRAY_SIZE;i++) {
        if (array[i]!=-1) {
            ans[index]=array[i];
            index++;
        }
    }
    for (i=0;i<index;i++) {
        printf("%d ",ans[i]);
    }
    return 0;
}
