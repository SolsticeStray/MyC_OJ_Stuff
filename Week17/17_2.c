#include <stdio.h>
#include <string.h>

int replace_str(char *s,char *t,char *g) {

    int count=0;
    int len_t=strlen(t);
    int len_g=strlen(g);
    char *pos=s;

    while ((pos=strstr(s,t))!=NULL) {
        count++;

        if (len_t!=len_g) {
            memmove(pos + len_g, pos + len_t, strlen(pos + len_t) + 1);
        }

        memcpy(pos,g,len_g);
        pos+=len_g;

    }

    return count;
}

int main(void) {

    char s[100], t[20], g[20];

    scanf("%s %s %s",s,t,g);

    int count=replace_str(s,t,g);

    printf("%s\n",s);
    printf("count=%d\n",count);

    return 0;
}