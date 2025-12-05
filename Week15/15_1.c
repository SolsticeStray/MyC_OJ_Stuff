#include <stdio.h>
#define SIZE 10

int com(int *a,int *b,int *c) {
    int i=0,j=0,k=0;
    while(i<SIZE && j<SIZE) {
        if(a[i]<b[j]) {
            c[k]=a[i];
            i++;
            k++;
        }
        else if (a[i]==b[j]) {
            i++;
            j++;
        }
        else {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    if (i<SIZE) {
        for (;i<SIZE;i++) {
            c[k]=a[i];
            k++;
        }
    }
    if (j<SIZE) {
        for (;j<SIZE;j++) {
            c[k]=b[j];
            k++;
        }
    }
    return (2*SIZE-k)/2;
}

int main(void) {
    int arr1[SIZE],arr2[SIZE],ans[SIZE*2];

    for (int i=0;i<SIZE;i++) {
        scanf("%d",&arr1[i]);
    }

    for (int i=0;i<SIZE;i++) {
        scanf("%d",&arr2[i]);
    }

    int count_repeat = com(arr1,arr2,ans);

    for (int i=0;i<2*SIZE-2*count_repeat;i++) {
        printf("%d ",ans[i]);
    }

    printf("\n");
    printf("count=%d\n",count_repeat);

    return 0;
}