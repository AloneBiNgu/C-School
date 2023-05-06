#include <bits/stdc++.h>

using namespace std;

const int maxN = 3e3 + 5;

struct Points {
    long long x, y;
};

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("triland.inp", "r", stdin);
        freopen("triland.out", "w", stdout);
    #endif

    cin >> n;
    vector<Points> args(n);

    for (Points &a : args) {
        cin >> a.x >> a.y;
    }


    return 0;
}