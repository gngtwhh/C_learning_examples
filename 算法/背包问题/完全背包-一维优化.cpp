// ��� P1616 ���Ĳ�ҩ
#include <bits/stdc++.h>
using namespace std;
unsigned long long f[10000001];
int main() {
    int m, n;
    cin >> m >> n;
    unsigned long long w, v;
    for (int i = 0;i < n;++i) {
        cin >> w >> v; // ������Ʒ�ı�������,���Ա߶�����
        for(int j=w;j<=m;++j){
            f[j]=max(f[j],f[j-w]+v);
        }
    }
    cout << f[m];

    return 0;
}