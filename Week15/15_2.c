#include <stdio.h>
#define SIZE 10

int findsub(int a[], int n, int b[]) {
    int idx = 0, i = 1, ascend_flag = (a[1] > a[0]);
    for (; i < n; i++) {
        if (ascend_flag && (a[i] < a[i - 1])) {
            ascend_flag = 0;
            b[idx++] = i-1;
        } else if (!ascend_flag && (a[i] > a[i - 1])) {
            ascend_flag = 1;
            b[idx++] = i-1;
        }
    }
    return idx;
}

int main(void) {
    int arr[SIZE], ans[SIZE];
    for (int k = 0; k < SIZE; k++) {
        scanf("%d", &arr[k]);
    }
    for (int k = 0; k < SIZE; k++) {
        printf("%d ", arr[k]);
    }
    int count = findsub(arr, SIZE, ans);
    printf("\n");
    for (int k = 0; k < count; k++) {
        printf("%d ", ans[k]);
    }
    printf("\n");
    printf("%d\n", count+1);
    return 0;
}
