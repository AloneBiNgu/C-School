#include <bits/stdc++.h>

using namespace std;

const int maxN = 1505;

struct Points {
    long long x, y, id;
};

int n;
bool checkId[maxN];
map<pair<long long, long long>, bool> m;

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

vector<Points> validateArgs(vector<Points> &args, bool checkId[]) {
    vector<Points> newArgs;

    for (auto it : args) {
        if (checkId[it.id] == true) {
            newArgs.push_back(it);
        }
    }
    
    return newArgs;
}

void Process(vector<Points> &hull) {
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

    long double dis = Dis(hull[pos1], hull[pos2]);
    if (hull[pos1].id > hull[pos2].id) {
        cout << fixed << setprecision(4) << dis << "\n";
        cout << hull[pos2].id << " " << hull[pos1].id << "\n";
    } else if (hull[pos1].id < hull[pos2].id) {
        cout << fixed << setprecision(4) << dis << "\n";
        cout << hull[pos1].id << " " << hull[pos2].id << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("dis.inp", "r", stdin);
        freopen("dis.out", "w", stdout);
    #endif

    cin >> n;
    vector<Points> args(n);

    int id = 1;
    // for (Points &a: args) {
    //     cin >> a.x >> a.y;
    //     a.id = id;
    //     id++;
    // }

    long long x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (m[{x, y}] < 1) {
            checkId[id] = true;
            args.push_back({x, y, id});
            m[{x, y}] = true;
        } else {
            checkId[id] = false;
        }
        id++;
    }

    args = validateArgs(args, checkId);
    
    auto Hull = convexHull(args);
    Process(Hull);
    return 0;
}