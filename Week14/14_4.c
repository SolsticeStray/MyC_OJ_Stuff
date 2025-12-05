#include <stdio.h>
#define MAX_ARRAY_SIZE 10

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int Del_findgcd(int a[],int n,int *f) {
    for (int i = 0; i < n; i++) {
        if (i%2==1) {
            a[i]=-1;
        }
    }
    int maxFactor = gcd(a[0],a[2]);
    for (int i = 2; i < n; i=i+2) {
        maxFactor = gcd(maxFactor,a[i]);
    }
    *f = maxFactor;
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            result ++;
        }
    }
    return result;
}

int main() {
    int input[MAX_ARRAY_SIZE];
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        scanf("%d",&input[i]);
    }
    int cd;
    Del_findgcd(input, MAX_ARRAY_SIZE, &cd);
    for (int i = 0; i < MAX_ARRAY_SIZE-2; i++) {
        if (input[i]!=-1) {
            printf("%d ",input[i]);
        }
    }
    if (input[MAX_ARRAY_SIZE-2]!=-1) printf("%d,",input[MAX_ARRAY_SIZE-2]);
    printf(" max common divisor is %d.\n",cd);
    return 0;
}
