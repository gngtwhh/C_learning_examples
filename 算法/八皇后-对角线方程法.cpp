#include <iostream>

#define MAX_N 51
using namespace std;
int n, sum, flag, ans[MAX_N];

void dfs(int step) { //step为行
    if (step == n + 1) {
        //if (flag < 3) {
        for (int i = 1; i <= n; ++i)
            printf("%d ", ans[i]);
        printf("\n");
        flag++;
        //}
        sum++;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        bool flag2 = true;
        if (step == 1) {
            ans[step] = i;
            dfs(step + 1);
        } else {
            for (int j = 1; j < step; ++j) {
                if (((i + step == ans[j] + j) || (i - step == ans[j] - j) || (i == ans[j]))) {
                    flag2 = false;
                    break;
                }
            }
            if (flag2) {
                ans[step] = i;
                dfs(step + 1);
            }
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    cout << sum;
    return 0;
}