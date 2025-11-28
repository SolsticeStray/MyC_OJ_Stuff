#include <stdio.h>
#define MAX_ARRAY_SIZE 10

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int array[MAX_ARRAY_SIZE];

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        scanf("%d", &array[i]);
    }

    int l = 0;
    int r = MAX_ARRAY_SIZE - 1;

    while (1) {

        while (l < MAX_ARRAY_SIZE && !isPrime(array[l])) {
            l++;
        }

        while (r >= 0 && !isPrime(array[r])) {
            r--;
        }

        if (l >= r) {
            break;
        }
        swap(&array[l], &array[r]);
        l++;
        r--;
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
