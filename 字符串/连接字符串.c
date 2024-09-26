#include <stdio.h>
#include <string.h>
int main()
{
    char a[100], b[100], c[200];
    int la, lb, i, j;
    scanf("%s%s", a, b);
    la = strlen(a);
    lb = strlen(b);
    for(i=0;i<la;++i){
        c[i]=a[i];
    }
    for(j=0;j<lb;++i,++j){
        c[i]=b[j];
    }
    c[i]='\0';
    printf("%s",c);
    return 0;
}