#include <stdio.h>

int CanBeDivided(int dividend,int divisor) {
    if (divisor==1) return 0;
    if (dividend%divisor==0) return 1;
    return CanBeDivided(dividend,divisor-1);
}

int isPrime(int n){
    if (n <= 1) return 0;
    return !CanBeDivided(n,n-1);
}

int main(void) {
    int a;
    scanf("%d",&a);
    printf("%d\n",isPrime(a));
    return 0;
}
