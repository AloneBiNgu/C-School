#include <bits/stdc++.h>

using namespace std;

struct Points {
    long double x, y;
};

int n;
Points bill;

bool ccw(Points A, Points B, Points C) {
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (C.x - A.x) * (B.y - A.y) > 0;
}

vector<Points> convexHull(vector<Points> &points) {
    sort(points.begin(), points.end(), [](Points a, Points b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    vector<Points> hull;
    hull.push_back(points[0]);
    
    for (int i = 1; i < points.size(); i++) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), points[i])) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    for (int i = points.size() - 2; i >= 0; i--) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), points[i])) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    if (hull.size() > 1) hull.pop_back();
    return hull;
}

long double Dis(Points &a, Points &b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

Points TrungDiem(Points &a, Points &b) {
    Points m;
    m.x = (a.x + b.x) / 2;
    m.y = (a.y + b.y) / 2;
    return m;
}

void Process(vector<Points> &hull) {
    long double ans = INT_MAX;

    for (int i = 0; i < hull.size(); i++) {
        int j = (i + 1) % hull.size();
        auto M = TrungDiem(hull[i], hull[j]);
        ans = min(ans, Dis(bill, M));
    }
    cout << fixed << setprecision(4) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("bill.inp", "r", stdin);
    freopen("bill.out", "w", stdout);

    cin >> n >> bill.x >> bill.y;
    vector<Points> args(n);

    for (int i = 0; i < n; i++) {
        cin >> args[i].x >> args[i].y;
    }

    auto Hull = convexHull(args);
    Process(Hull);
    return 0;
}