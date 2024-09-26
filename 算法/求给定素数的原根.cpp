//求模m的所有原根
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> get_prime_factors(int n) {
    vector<int> vec;
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0)
            vec.push_back(i);
        while (n % i == 0)
            n /= i;
    }
    return vec;
}

int square_and_multiply(int m, int e, int n) {
    int c = 1;
    while (e > 0) {
        if (e & 1)
            c = c * m % n;
        m = m * m % n;
        e >>= 1;
    }
    return c;
}

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

vector<int> get_primitive_root(int m) {
    vector<int> vec;
    vector<int> prime_factors;
    prime_factors = get_prime_factors(m - 1);
    int a;
    for (a = 2; a <= m - 1; ++a) {
        int flag = 1;
        for (auto p: prime_factors) {
            if (1 == square_and_multiply(a, (m - 1) / p, m)) {
                flag = 0;
                break;
            }
        }
        if (flag) break;
    }
    for (int d = 1; d <= m - 1; ++d) {
        if (gcd(d, m - 1) == 1)
            vec.push_back(square_and_multiply(a, d, m));
    }
    return vec;
}

int main() {
    vector<int> pr_vec;
    int m;
    cin >> m;
    pr_vec = get_primitive_root(m);
    for (auto i: pr_vec)
        cout << i << " ";
    return 0;
}
