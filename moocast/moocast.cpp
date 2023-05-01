#include <bits/stdc++.h>

using namespace std;

const int maxN = 25e3 + 5;

struct Data {
    int x, y, distance;
} args[maxN];

int n;
int parent[maxN], r[maxN];

int Find(int u) {
    return parent[u] == u ? u : parent[u] = Find(parent[u]);
}

bool CanJoint(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;
    if (r[u] == r[v]) r[u]++;
    if (r[u] < r[v]) {
        parent[u] = v;
    } else {
        parent[v] = u;
    }
    return true;
}

bool cmp(Data &a, Data &b) {
    return a.distance < b.distance;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("moocast.inp", "r", stdin);
        freopen("moocast.out", "w", stdout);
    #endif

    cin >> n;
    vector<int> x(n), y(n);
    vector<Data> args(n);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        r[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            int distance = pow(dx, 2) + pow(dy, 2);
            args.push_back({i, j, distance});
        }
    }

    sort(args.begin(), args.end(), cmp);

    int last;
    for (auto it : args) {
        if (CanJoint(it.x, it.y)) {
            last = it.distance;
        }
    }

    cout << last << "\n";
    return 0;
}