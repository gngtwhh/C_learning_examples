#include <stdio.h>
#include <string.h>
int fun(char a[]) {
    int len = strlen(a);
    for (int i = 0; i < len / 2; ++i) {
        if (a[i] != a[len - i - 1])
            return 0;
    }
    return 1;
}
int main() {
    char a[100];
    int i,n,number=0;
    scanf("%d\n", &n);
    for(i=0;i<n;++i)
    {
        gets(a);
        number+=fun(a);
    }
    printf("%d", number);
    return 0;
}