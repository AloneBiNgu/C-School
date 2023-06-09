#include <bits/stdc++.h>

using namespace std;

int n;

int main() {

    freopen("bcfibo.inp", "r", stdin);
    freopen("bcfibo.out", "w", stdout);

    cin >> n;

    int f[n + 5];
    f[0] = 0, f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % 1000000007;
    }

    cout << f[n];
    return 0;
}