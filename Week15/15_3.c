#include <stdio.h>
#define ROW 5
#define COLUMN 5

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(void) {

    int matrix[ROW][COLUMN];
    int diag[ROW];
    int i,j;

    /* input values into the matrix */
    for (i=0; i < ROW; i++) {
        for (j=0; j < COLUMN; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    /* transformation */
    for (i=0;i<ROW;i++) {
        int sum=0;
        for(j=0;j<COLUMN;j++) {
            sum += matrix[i][j];
        }
        matrix[i][4-i]=sum;
        diag[i]=matrix[i][4-i];
    }

    selection_sort(diag, ROW);

    for(i=0;i<ROW;i++) {
        for(j=0;j<COLUMN;j++) {
            if (i+j==4) printf("%d ",diag[i]);
            else printf("0 ");
        }
        printf("\n");
    }

    return 0;
}