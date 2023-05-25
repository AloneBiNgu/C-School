#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e4 + 5;

struct Data {
    int x, y, z;
} args[maxN];

int n;
int parent[maxN], r[maxN];

int find(int u) {
    return u == parent[u] ? u : parent[u] = find(parent[u]);
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (r[u] == r[v]) r[u]++;
    if (r[u] < r[v]) {
        parent[u] = v;
    } else {
        parent[v] = u;
    }
    return true;
}//

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("ioibin.inp", "r", stdin);
    freopen("ioibin.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        r[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> args[i].x >> args[i].y >> args[i].z;
    }

    for (int i = 0; i < n; i++) {
        auto it = args[i];
        if (it.z == 1) {
            join(it.x, it.y);
        } else {
            cout << (find(it.x) == find(it.y) ? 1 : 0) << "\n";
        }
    }
    return 0;
}
