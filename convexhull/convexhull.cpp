#include <bits/stdc++.h>

using namespace std;

struct Points {
    int x, y;
};
int n;
long double dt;

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

void Calc(vector<Points> &hull, long double &dt) {
    dt = 0.0;

    int n = hull.size();

    for (int i = 0; i < n; i++) {
        dt += hull[i].x * hull[(i + 1) % hull.size()].y - hull[i].y * hull[(i + 1) % hull.size()].x;
    }

    dt = fabs(dt) / 2.0;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("convexhull.inp", "r", stdin);
    freopen("convexhull.out", "w", stdout);

    cin >> n;
    vector<Points> args(n);
    for (Points &x : args) {
        cin >> x.x >> x.y;
    }
    auto Hull = convexHull(args);

    cout << Hull.size() << "\n";
    Calc(Hull, dt);

    cout << fixed << setprecision(1) << dt << "\n";

    int oldX = Hull[0].x, oldY = Hull[0].y;
    int pos = 0;
    for (int i = 1; i < Hull.size(); i++) {
        if (Hull[i].y < oldY) {
            oldY = Hull[i].y;
            oldX = Hull[i].x;
            pos = i;
        }
        if (oldY == Hull[i].y && oldX > Hull[i].x) {
            oldX = Hull[i].x;
            oldY = Hull[i].y;
            pos = i;
        }
    }

    // cout << pos << "\n";

    for (int i = pos; i >= 0; i--) {
        cout << Hull[i].x << " " << Hull[i].y << "\n";
    }

    for (int i = Hull.size() - 1; i > pos; i--) {
        cout << Hull[i].x << " " << Hull[i].y << "\n";
    }
    return 0;
}