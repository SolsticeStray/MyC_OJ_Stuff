#include <stdio.h>
#include <math.h>

double f(double x) {
    return 2 * x + 1;
}

double integral(double a,double b,long n,double (*p)(double)) {
    double h = (b - a) / n;
    double sum = 0.0;
    if (*p==cos) {
        for (long i = 0; i < n; i++) {
            sum += (p(a + i * h) + p(a + (i + 1) * h)) / 2.0;
        }
    } else if (*p==sin) {
        for (long i = 0; i < n; i++) {
            sum += (p(a + i * h) + p(a + (i + 1) * h)) / 2.0;
        }
    } else {
        for (long i = 0; i < n; i++) {
            sum += (p(a + i * h) + p(a + (i + 1) * h)) / 2.0;
        }
    }
    return sum * h;
}

int main(void) {
    double a,b;
    int n;
    scanf("a=%lf,b=%lf,n=%d",&a,&b,&n);
    printf("integral cos:%.6lf\n",integral(a,b,n,cos));
    printf("integral sin:%.6lf\n",integral(a,b,n,sin));
    printf("integral 2x+1:%.6lf\n",integral(a,b,n,f));
    return 0;
}