#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;

struct Points {
    long long x, y, id;
};

int n;
bool checkId[maxN];
map<pair<long long, long long>, bool> m;

bool ccw(Points &a, Points &b, Points &c) {
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (c.x - a.x) * (b.y - a.y) > 0;
}

vector<Points> convexHull(vector<Points> &args) {
    sort(args.begin(), args.end(), [&args](Points &a, Points &b) {
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

long double TichCheo(Points a, Points b, Points c) {
    Points AB, BC;
    AB.x = b.x - a.x, AB.y = b.y - a.y;
    BC.x = c.x - b.x, BC.y = c.y - b.y;

    return (AB.x * BC.y - BC.x * AB.y);
}

vector<Points> newHull(vector<Points> &hull, bool check[], int pos) {
    vector<Points> newH;

    for (int i = pos; i >= 0; i--) {
        if (check[hull[i].id] == true) {
            newH.push_back(hull[i]);
        }
    }

    for (int i = hull.size() - 1; i >= pos + 1; i--) {
       if (check[hull[i].id] == true) {
            newH.push_back(hull[i]);
        } 
    }
    return newH;
}

void Process(vector<Points> &hull) {
    bool check[maxN];
    
    for (int i = 0; i < hull.size(); i++) check[hull[i].id] = true;
    for (int i = 0; i < hull.size(); i++) {
        int j = (i + 1) % hull.size();
        int k = (j + 1) % hull.size();

        if (TichCheo(hull[i], hull[j], hull[k]) == 0) {
            check[hull[j].id] = false;
        }
    }

    Points tmp = hull[0];
    int pos = 0;
    long double dt = 0.0;

    for (int i = 1; i < hull.size(); i++) {
        if (tmp.y > hull[i].y) {
            tmp = hull[i];
            pos = i;
        }
        if (tmp.y == hull[i].y && tmp.x > hull[i].x) {
            tmp = hull[i];
            pos = i;
        }
    }

    auto newH = newHull(hull, check, pos);
    
    for (int i = 0; i < newH.size(); i++) {
        int j = (i + 1) % newH.size();
        dt += (newH[i].x * newH[j].y) - (newH[j].x * newH[i].y);
    }
    dt = fabs(dt) / 2.0;

    cout << newH.size() << "\n" << fixed << setprecision(1) << dt << "\n";
    for (auto it : newH) cout << it.x << " " << it.y << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("convexhull.inp", "r", stdin);
        freopen("convexhull.out", "w", stdout);
    #endif

    cin >> n;
    vector<Points> args(n);

    int id = 1;
    long long x, y;
    // for (Points &a : args) {
    //     cin >> a.x >> a.y;
    //     a.id = id;
    //     id++;
    //     m[{a.x, a.y}] = true;
    // }

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