#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact_person {
    long id;
    char name[10];
    char sex[2];
} PS;

int del(PS *p1, int m, PS *p2, int n) {
    int write = 0;
    for (int i = 0; i < m; i++) {
        int is_dupulicated = 0;
        for (int j = 0; j < n; j++) {
            if (p1[i].id == p2[j].id) {
                is_dupulicated = 1;
                break;
            }
        }
        if (!is_dupulicated) {
            if (write < m) p1[write++] = p1[i];    //skip duplicates
        }
    }
    return m - write;
}

int merge(PS *p1, int m, PS *p2,int n) {

    int repeatCount = del(p1,m,p2,n);    // remove duplicates first

    int m_updated = m - repeatCount;

    int idx1 = m_updated-1;
    int idx2 = n-1;
    int idx_merged = m_updated + n - 1;

    while (idx1>=0 && idx2>=0) {

        if ( p2[idx2].id < p1[idx1].id ) {
            p2[idx_merged--] = p1[idx1--];
        } else {
            p2[idx_merged--] = p2[idx2--];
        }

    }

    while (idx1>=0) {
        p2[idx_merged--] = p1[idx1--];
    }

    return n + m_updated;
}

int cmp(const void *p1, const void *p2) {

    PS *a = (PS *)p1;
    PS *b = (PS *)p2;

    int sex_cmp = strcmp(a->sex, b->sex);

    if (sex_cmp != 0) {
        return sex_cmp;
    }

    return strcmp(a->name, b->name);

}

void sort(PS *p, int n) {

    qsort(p, n, sizeof(PS), cmp);

}

void display(PS *p, int n) {

    printf("ID NAME SEX\n");

    for (int i = 0; i < n; i++) {
        printf("%ld %s %s\n", p[i].id, p[i].name, p[i].sex);
    }

}

int main(void) {

    PS a[10]={{101, "tom","m"},{103,"mary","f"},{104,"mark","m"},{105,"julia","f"},{106, "sara","f"}};
    PS b[20]={{102, "mark","m"},{104,"mark","m"}};

    printf("a:\n");

    display(a, 5);

    printf("b:\n");

    display(b, 2);

    printf("a:\n");

    int repeatCount=del(a,10,b,10);

    display(a,10-repeatCount);

    printf("b:\n");

    int len_b_updated=merge(a,10-repeatCount,b,2);

    display(b,len_b_updated);

    printf("a:\n");

    sort(a,10-repeatCount);

    display(a,10-repeatCount);

    return 0;

}