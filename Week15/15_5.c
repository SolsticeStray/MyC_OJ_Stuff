#include <stdio.h>
#define LEN 5

int find_common_elements(int set[LEN][LEN], int common[]) {
    int count = 0;
    for (int j = 0; j < LEN; j++) {
        int is_common = 1;
        for (int i = 1; i < LEN; i++) {
            int found = 0;
            for (int k = 0; k < LEN; k++) {
                if (set[0][j] == set[i][k]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                is_common = 0;
                break;
            }
        }
        if (is_common) {
            common[count++] = set[0][j];
        }
    }
    return count;
}

int bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return 0;
}

int main(void) {
    //input
    int set[LEN][LEN],ans[LEN];
    int i,j;
    for (i=0;i<LEN;i++) {
        for (j=0;j<LEN;j++) {
            scanf("%d", &set[i][j]);
        }
    }
    //process&sort
    int count = find_common_elements(set,ans);
    bubble_sort(ans,count);
    //output
    for (i=0;i<count;i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}