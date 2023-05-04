#include<bits/stdc++.h>
using namespace std;

#define maxN 100005
int n, a[maxN], q;
long long st[maxN * 4];

void update(int id, int l, int r, int i, int val){
    if (l > i || r < i) return;
    if (l == r){
        st[id] = val;
        return;
    }
    int mid = (l + r)/2;
    update(id * 2, l, mid, i, val);
    update(id * 2 + 1, mid + 1, r, i, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

long long query(int id, int l, int r, int u, int v){
    if (r < u || l > v) return 0;
    if (u <= l && r <= v) return st[id];

    int mid = (l + r)/2;
    long long get1 = query(id * 2, l, mid, u, v);
    long long get2 = query(id * 2 + 1, mid + 1, r, u, v);
    return get1 + get2;
}

int main(){
    cin >> n >> q;
    for (int i = 1; i <= q; i++){
        int type, x, y; cin >> type >> x >> y;
        if (type == 1){
            update(1, 1, n, x, y);
        } else {
            cout << query(1, 1, n, x, y) << "\n";
        }
    }

    return 0;
}
