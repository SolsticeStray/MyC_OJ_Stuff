#include <stdio.h>

double e,f;

void fun(char op,double a,double b,double c,double d) {
    if (op=='+') e=a+c,f=b+d;
    if (op=='-') e=a-c,f=b-d;
    if (op=='*') e=a*c-b*d,f=a*d+b*c;
}

int main(void) {
    double a,b,c,d;
    char op;
    scanf("(%lf+%lfi)%c(%lf+%lfi)",&a,&b,&op,&c,&d);
    fun(op,a,b,c,d);
    printf("(%.6lf+%.6lfi)%c(%.6lf+%.6lfi)=",a,b,op,c,d);
    printf("(%.6lf)+(%.6lf)i\n",e,f);
    return 0;
}