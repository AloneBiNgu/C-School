#include <bits/stdc++.h>

using namespace std;

struct Points {
    int x, y;
};
int n;
vector<int> path;

int ccw(Points A, Points B, Points C) {
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (C.x - A.x) * (B.y - A.y);
}

vector<Points> convexHull(vector<Points> &points) {
    sort(points.begin(), points.end(), [](Points a, Points b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    points.resize(unique(points.begin(), points.end()) - points.begin());

    vector<Points> hull(points.size() + 1);
    
    for (int i = 0; i < points.size(); i++) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
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

    if (hull.size() > 1) {
        hull.pop_back();
    }
    return hull;
}

vector<Points> find(vector<Points> &hull) {
    vector<Points> boundary;
    for (int i = 0; i < hull.size(); i++) {
        boundary.push_back(hull[i]);
        if (i + 1 < hull.size() && !ccw(hull[i], hull[i + 1], hull[(i + 2) % hull.size()])) {
            boundary.push_back(hull[i + 1]);
        }
    }
    return boundary;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cay.inp", "r", stdin);
    freopen("cay.out", "w", stdout);

    cin >> n;
    vector<Points> args(n);

    for (Points &a : args) {
        cin >> a.x >> a.y;
    }

    auto Hull = convexHull(args);
    for (auto it : Hull) {
        cout << it.x << " " << it.y << "\n"
    }
    return 0;
}