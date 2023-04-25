#include <bits/stdc++.h>

using namespace std;

struct Points {
    int x, y;
};

int n;
vector<Points> args;

int TichCheo(Points a, Points b) {
    return (a.x * b.y - b.x * a.y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("tripoint.inp", "r", stdin);
    freopen("tripoint.out", "w", stdout);

    cin >> n;
    args.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> args[i].x >> args[i].y;
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         dp[i][j] = tich
    //     }
    // }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int x1 = args[i].x, y1 = args[i].y;
                int x2 = args[j].x, y2 = args[j].y;
                int x3 = args[k].x, y3 = args[k].y;
                if ((x3 - x1) * (y2 - y1) == (x2 - x1) * (y3 - y1)) ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}