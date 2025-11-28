#include <stdio.h>
#define ARRAY_SIZE 10

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int InsertSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return 0;
}

int mpsort(int x[]) {
    int MaxEvenNum = -1,LastPrimeNum = -1;
    int evenindex=-1, primeindex=-1;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (x[i] % 2 == 0) {
            if (x[i] > MaxEvenNum) {
                MaxEvenNum = x[i];
                evenindex = i ;
            }
        }
    }
    for (int i = ARRAY_SIZE-1; i >= 0; i--) {
        if (isPrime(x[i])) {
            LastPrimeNum=x[i];
            primeindex = i ;
            break;
        }
    }
    if (MaxEvenNum == -1 || LastPrimeNum == -1) return -1;
    int start = evenindex < primeindex ? evenindex : primeindex;
    int end = evenindex > primeindex ? evenindex : primeindex;
    int count = end - start + 1;

    InsertSort(x+start, count);
    return count;
}

int main(void) {
    int x[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", x + i);
    }
    int t=mpsort(x);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
    printf("t=%d\n", t);
    return 0;
}