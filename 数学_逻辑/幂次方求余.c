#include<stdio.h>
#include<math.h>
int main() {
    int a, m, k,flag;
    while (1) {
        flag=scanf("%d%d%d", &a, &k, &m);
        if(flag!=3)
            break;
        int temp = 1;
        for (int t = 1; t <= k; ++t) {
            temp *= a;
            temp %= m;
        }
        printf("%d\n", temp);
    }
    return 0;
}