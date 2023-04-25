#include <bits/stdc++.h>

using namespace std;

struct Points {
    double x, y;
};

int n;

double Dis(Points a, Points b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

bool ccw(Points A, Points B, Points C) {
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (C.x - A.x) * (B.y - A.y) > 0;
}

vector<Points> ConvexHull(vector<Points> &args) {
    sort(args.begin(), args.end(), [&args](Points &A, Points &B) {
        if (A.x != B.x) return A.x < B.x;
        return A.y < B.y;
    });

    vector<Points> hull;
    hull.push_back(args[0]);

    for (int i = 1; i < args.size(); i++) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), args[i])) {
            hull.pop_back();
        }
        hull.push_back(args[i]);
    }

    for (int i = args.size() - 2; i >= 0; i--) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), args[i])) {
            hull.pop_back();
        }
        hull.push_back(args[i]);
    }

    if (hull.size() > 1) hull.pop_back();
    return hull;
}

long double angles(Points a, Points b, Points c) {
    Points BA, BC;
    BA.x = a.x - b.x, BA.y = a.y - b.y;
    BC.x = c.x - b.x, BC.y = c.y - b.y;

    long double tu = BA.x * BC.x + BC.y * BA.y;
    long double mau = sqrt((pow(BA.x, 2) + pow(BA.y, 2)) * (pow(BC.x, 2) + pow(BC.y, 2)));
    return tu / mau;
}

long double Find(vector<Points> hull) {
    long double ans = 0.000;
    for (int i = 0; i < hull.size(); i++) {
        for (int j = 0; j < hull.size(); j++) {
            for (int k = 0; k < hull.size(); k++) {
                ans = max(ans, acos(angles(hull[i], hull[j], hull[k])));
            }
        }

    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("gocmax.inp", "r", stdin);
    freopen("gocmax.out", "w", stdout);

    cin >> n;
    vector<Points> args(n);

    for (Points &a : args) {
        cin >> a.x >> a.y;
    }

    auto Hull = ConvexHull(args);
    cout << fixed << setprecision(3) << Find(Hull) << "\n";
    
    return 0;
}