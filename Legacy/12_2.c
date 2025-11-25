#include <stdio.h>

void decimal_to_base(int n,int base) {
    if (n == 0) {
        return;
    }
    decimal_to_base(n / base, base);
    int remainder = n % base;
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", 'A' + (remainder - 10));
    }
}

int main(void) {
    int input,base;
    scanf("%d %d",&input,&base);
    decimal_to_base(input, base);
    return 0;
}
