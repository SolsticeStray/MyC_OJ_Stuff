#include <stdio.h>
#define LEN 4

int NextPrime(int n) {
    int candidate = n + 1;
    while (1) {
        int is_prime = 1;
        for (int i = 2; i * i <= candidate; i++) {
            if (candidate % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            return candidate;
        }
        candidate++;
    }
}

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    /*declare*/
    int arr[LEN][LEN];
    /*input*/
    int i,j;
    for (i=0;i<LEN;i++) {
        for (j=0;j<LEN;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    /*transformation*/
    int count=0;
    for (i=0;i<LEN;i++) {
        for (j=0;j<=i;j++) {
            if (!isPrime(arr[i][j])) {
                arr[i][j] = 0;
            }
            if (isPrime(arr[i][j])) {
                arr[i][j]=NextPrime(arr[i][j]);
                count++;
            }
        }
    }
    /*output*/
    for (i=0;i<LEN;i++) {
        for (j=0;j<LEN;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("count=%d\n",count);
    return 0;
}