#include <stdio.h>

int main(void) {
    int a[10]={5,23,28,34,43,45,56,60,67,90};
    int target;
    scanf("%d",&target);
    int left=0, right=9, mid;
    int found=0;
    while(left <= right) {
        mid = (left + right) / 2;
        if(a[mid] == target) {
            found = 1;
            break;
        } else if(a[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if(found) {
        printf("%d\n", mid);
    } else {
        printf("not found\n");
    }
    return 0;
}