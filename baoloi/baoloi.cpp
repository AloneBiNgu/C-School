#include <bits/stdc++.h>

using namespace std;

struct Points {
    int x, y;
};
int n;
double dt, chuvi;

double Dis(Points a, Points b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

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

void Calc(vector<Points> &args, double &dt, double &chuvi) {
    vector<Points> hull = convexHull(args);

    chuvi = 0.0;
    dt = 0.0;

    int n = hull.size();

    for (int i = 0; i < n; i++) {
        chuvi += Dis(hull[i], hull[(i + 1) % n]);
        dt += hull[i].x * hull[(i + 1) % n].y - hull[i].y * hull[(i + 1) % n].x;
    }

    dt = fabs(dt) / 2.0;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("baoloi.inp", "r", stdin);
    freopen("baoloi.out", "w", stdout);

    cin >> n;
    vector<Points> args(n);
    for (Points &x : args) {
        cin >> x.x >> x.y;
    }
    auto Hull = convexHull(args);

    // for (auto it : Hull) cout << it.x << " " << it.y << "\n";

    cout << Hull.size() << "\n";
    Calc(args, dt, chuvi);

    cout << fixed << setprecision(3) << chuvi << "\n" << dt << "\n";
    return 0;
}