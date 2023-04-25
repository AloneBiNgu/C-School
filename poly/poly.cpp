#include <bits/stdc++.h>

using namespace std;

const int maxN = 1505;

struct point {
    int x, y;
};

int n;
vector<point> args(maxN);

double area(point a, point b, point c) {
    return fabs((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y)) / 2.0;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("poly.inp", "r", stdin);
    freopen("poly.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> args[i].x >> args[i].y;
    }

    double max_area = 0;
    for (int i = 0; i <= n - 4; i++) {
        for (int j = i + 1; j <= n - 3; j++) {
            for (int k = j + 1; k <= n - 2; k++) {
                for (int l = k + 1; l <= n - 1; l++) {
                    double cur_area = area(args[i], args[j], args[k]) + area(args[i], args[k], args[l]);
                    max_area = max(max_area, cur_area);
                }
            }
        }
    }

    cout << fixed << setprecision(1) << max_area << endl;

    return 0;
}