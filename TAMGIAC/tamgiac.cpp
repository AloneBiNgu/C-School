#include <bits/stdc++.h>

using namespace std;

struct Points {
    int x, y;
};

int n;

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("tamgiac.inp", "r", stdin);
    // freopen("tamgiac.out", "w", stdout);

    cin >> n;
    vector<Points> args(n * 3);

    for (Points &a : args) {
        cin >> a.x >> a.y;
    }

    for (auto it : args) cout << it.x << " " << it.y << "\n";
    // auto Hull = convexHull(args);
    // for (auto it : Hull) cout << it.x << " " << it.y << "\n";
    
    return 0;
}