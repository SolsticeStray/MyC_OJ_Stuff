#include <stdio.h>

int reverse(int n) {
    int reversed = 0;
    while (n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return reversed;
}

int isPlindrome(int n) {
    return n == reverse(n);
}

int fun(long n,long *hw) {
    int i = 0;
    while (isPlindrome(n)!=1) {
        n = n + reverse(n);
        i++;
    }
    if (isPlindrome(n)==1) {
        *hw = n;
        return i;
    }
    if (i>10000) return -1;
}

int main(void) {
    long a,c;
    long b=0;
    scanf("%d",&a);
    c=fun(a,&b);
    printf("%d,%d",b,c);
    return 0;
}
