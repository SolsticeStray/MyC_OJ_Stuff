#include <stdio.h>
#define ROW 5

void swap(int *x, int *y) {
    int temp = *x;
    *x=*y;
    *y=temp;
}

void line_sort(int a[][4],int b[],int n) {

    for (int i=0;i<n;i++) {
        for (int j=0;j<4;j++) {
            *(b+i)+=*(*(a+i)+j);
        }
    }

    for (int i=0;i<n;i++) {
        int min_idx=i;
        for (int j=i+1;j<n;j++) {
            if (b[min_idx]>b[j]) {
                min_idx=j;
            }
        }
        if (i!=min_idx) {
            swap(&b[i],&b[min_idx]);
            for (int k=0;k<4;k++) {
                swap(&a[i][k],&a[min_idx][k]);
            }
        }
    }

}

int main(void) {

    int arr[ROW][4];
    int row_sum[ROW]={0};

    for (int i=0;i<ROW;i++) {
        for (int j=0;j<4;j++) {
            scanf("%d",&arr[i][j]);
        }
    }

    line_sort(arr,row_sum,ROW);

    for (int i=0;i<ROW;i++) {
        for (int j=0;j<4;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    printf("sum\n");

    for (int i=0;i<ROW;i++) {
        printf("%d ",row_sum[i]);
    }

    return 0;
}