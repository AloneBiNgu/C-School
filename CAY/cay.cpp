#include <bits/stdc++.h>

using namespace std;

struct Points {
    int x, y, id;
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

long double TichCheo(Points a, Points b, Points c) {
    Points AB, BC;
    AB.x = b.x - a.x, AB.y = b.y - a.y;
    BC.x = c.x - b.x, BC.y = c.y - b.y;

    return (AB.x * BC.y - BC.x * AB.y);
}

void Process(vector<Points> &hull) {
    Points tmp;
    int pos = 0, cnt = 0;
    tmp.x = hull[0].x, tmp.y = hull[0].y;

    bool check[260];
    for (int i = 0; i < hull.size(); i++) {
        check[hull[i].id] = true;
    }
    for (int i = 0; i < hull.size(); i++) {
        int j = (i + 1) % hull.size();
        int k = (j + 1) % hull.size();

        if (TichCheo(hull[i], hull[j], hull[k]) == 0 && check[hull[j].id] == true) {
            check[hull[j].id] = false;
        }
    }

    for (int i = 1; i < hull.size(); i++) {
        if (tmp.y > hull[i].y && hull[i].y >= 0) {
            tmp.x = hull[i].x;
            tmp.y = hull[i].y;
            pos = i;
        }
        if (tmp.y == hull[i].y && tmp.x < hull[i].x) {
            tmp.x = hull[i].x;
            tmp.y = hull[i].y;
            pos = i;
        }
        // if (tmp.x < hull[i].x) {
        //     tmp.x = hull[i].x;
        //     tmp.y = hull[i].y;
        //     pos = i;
        // }
        // if (tmp.x == hull[i].id && tmp.y > hull[i].y) {
        //     tmp.x = hull[i].x;
        //     tmp.y = hull[i].y;
        //     pos = i;
        // }
    }

    // cout << pos << "\n";
    // cout << tmp.x <<  " " << tmp.y  << "\n";

    // for (auto it : hull) {
    //     cout << it.x << " " << it.y << " ID: " << it.id << "\n";
    // }
    
    for (int i = 0; i < hull.size(); i++) {
        if (check[hull[i].id] == true) cnt++;
    }
    
    cout << cnt << "\n";
    for (int i = pos; i >= 0; i--) {
        if (check[hull[i].id] == true) {
            cout << hull[i].id << " ";
        }
    }
    
    for (int i = hull.size() - 1; i >= pos + 1; i--) {
        if (check[hull[i].id] == true) {
            cout << hull[i].id << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cay.inp", "r", stdin);
    freopen("cay.out", "w", stdout);

    cin >> n;
    vector<Points> args(n);

    int id = 1;
    for (Points &a : args) {
        cin >> a.x >> a.y;
        a.id = id;
        id++;
    }

    auto Hull = convexHull(args);
    // for (auto it : Hull) {
    //     cout << it.x << " " << it.y << "\n";
    // }
    Process(Hull);
    return 0;
}