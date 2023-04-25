#include <bits/stdc++.h>

using namespace std;

const int maxN = 3e3 + 5;

struct Points {
    int x, y;
};

int n;
vector<Points> args;

double area(const vector<Points> &args) {
    double res = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)args.size() - 1; i++) {
        x1 = args[i].x, x1 = args[i + 1].x;
        y1 = args[i].y; y2 = args[i + 1].y;
        res += (x1 * y2 - x2 * y1);
    }
    return fabs(res) / 2.0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("triland.inp", "r", stdin);
    freopen("triland.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> args[i].x >> args[i].y;
    cout << area(args) << "\n";
    return 0;
}