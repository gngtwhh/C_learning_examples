#include <stdio.h>

void primeFactorization(int n) {
    printf("%d = ", n);

    // 从2开始依次尝试
    for (int i = 2; i <= n; i++) {
        // 如果i是n的因数，将i输出，并将n除以i
        while (n % i == 0) {
            printf("%d", i);
            n /= i;
            if (n != 1) {
                printf(" x ");
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    primeFactorization(n);
    return 0;
}

#if 0

#include <stdio.h>

void primeFactorization(int n) {
    printf("%d = ", n);
    int cnt = 0;
    // 从2开始依次尝试
    for (int i = 2; i <= n; i++) {
        // 如果i是n的因数，将i输出，并将n除以i
        if (n % i == 0) {
            printf("%d", i);
            cnt = 0;
        }
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        printf("^%d", cnt);
        if (n != 1) {
            printf(" × ");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    primeFactorization(n);
    return 0;
}

#endif