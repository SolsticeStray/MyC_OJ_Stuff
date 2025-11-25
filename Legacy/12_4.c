#include <stdio.h>
#define N 101

int isUgly(int num) {
    if (num <= 0) return 0;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return num == 1;
}

int main() {
    int count=0, num=1;
    while (count<N) {
        if (isUgly(num)) count++;
        num++;
    }
    printf("%d\n", num-1);
    return 0;
}
