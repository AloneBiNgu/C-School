#include <bits/stdc++.h>

using namespace std;

struct Points {
    int x, y;
};

int n;
long double ans = 0.0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("poly.inp", "r", stdin);
        freopen("poly.out", "w", stdout);
    #endif

    cin >> n;
    vector<Points> args(n);

    for (Points &a : args) {
        cin >> a.x >> a.y;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    ans = max(ans, arg)
                }
            }
        }
    }
    return 0;
}