#include <bits/stdc++.h>

using namespace std;

int n;

long long Solv(int k, vector<long double> &x, vector<long double> &y) {
    vector<long double> a(k);

    for (int i = 0; i < k; i++) {
        long double dy = y[i] - y[k];
        if (dy != 0) a[i] = (x[i] - x[k]) / dy;
        else a[i] = 1e9;
    }

    sort(a.begin(), a.end());

    long long res = 0, cnt = 1;
    for (int i = 1; i < k; i++) {
        if (a[i] != a[i - 1]) {
            res += cnt * (cnt - 1) / 2;
            cnt = 0;
        }
        cnt++;
    }

    res += cnt * (cnt - 1) / 2;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("tripoint.inp", "r", stdin);
        freopen("tripoint.out", "w", stdout);
    #endif

    cin >> n;
    vector<long double> x(n), y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    long long res = 0;
    for (int i = 2; i < n; i++) {
        res += Solv(i, x, y);
    }
    cout << res << "\n";
    return 0;
}