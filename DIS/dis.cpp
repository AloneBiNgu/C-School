#include <bits/stdc++.h>

using namespace std;

struct Points1 {
    int x, y;
    long double distance;
};

struct Points {
    int x, y, id;
};

int n;

long double Dis(Points &a, Points &b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

bool ccw(Points &a, Points &b, Points &c) {
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (c.x - a.x) * (b.y - a.y) > 0;
}

vector<Points> convexHull(vector<Points> &args) {
    sort(args.begin(), args.end(), [&](Points &a, Points &b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
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

// vector<Points1> Find(int u, int v) {

// }

void Process(vector<Points> &hull) {
    // vector<Points1> e;
    
    // for (int i = 0; i < hull.size(); i++) {
    //     for (int j = i + 1; j < hull.size(); j++) {
    //         e.push_back({hull[i].id, hull[j].id, Dis(hull[i], hull[j])});
    //     }
    // }

    // sort(e.begin(), e.end(), [&](Points1 &a, Points1 &b) {
    //     return a.distance < b.distance;
    // });

    // auto res = e[0];
    // cout << fixed << setprecision(4) << res.distance << "\n";
    // cout << res.x << " " << res.y << "\n";
    Points tmp = hull[0], tmp1 = hull[0];
    int pos1 = 0, pos2 = 0;

    for (int i = hull.size(); i >= 0; i--) {
        if (tmp.y > hull[i].y) {
            tmp = hull[i];
            pos1 = i;
        }
        if (tmp.y == hull[i].y && tmp.x > hull[i].x) {
            tmp = hull[i];
            pos1 = i;
        }
    }

    for (int i = 1; i < hull.size(); i++) {
        if (tmp1.y < hull[i].y) {
            tmp1 = hull[i];
            pos2 = i;
        }
        if (tmp1.y == hull[i].y && tmp1.x < hull[i].x) {
            tmp1 = hull[i];
            pos2 = i;
        }
    }

    // for (auto it : e) {
    //     cout << it.x << " " << it.y << " " << fixed << setprecision(4) << it.distance << "\n";
    // }

    // cout << tmp.x << " " << tmp.y << " " << tmp.id << "\n";
    // cout << tmp1.x << " " << tmp1.y << " " << tmp1.id << "\n";

    long double dis = Dis(hull[pos1], hull[pos2]);
    if (hull[pos1].id > hull[pos2].id) {
        cout << fixed << setprecision(4) << dis << "\n";
        cout << hull[pos2].id << " " << hull[pos1].id << "\n";
    } else if (hull[pos1].id < hull[pos2].id) {
        cout << fixed << setprecision(4) << dis << "\n";
        cout << hull[pos1].id << " " << hull[pos2].id << "\n";
    }

    // cout << pos1 << " " << pos2 << "\n";
    // // cout << tmp.x << " " << tmp.y << " " << tmp.id << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("dis.inp", "r", stdin);
        freopen("dis.out", "w", stdout);
    #endif

    cin >> n;
    vector<Points> args(n);

    int id = 1;
    for (Points &a: args) {
        cin >> a.x >> a.y;
        a.id = id;
        id++;
    }
    
    auto Hull = convexHull(args);
    Process(Hull);
    return 0;
}