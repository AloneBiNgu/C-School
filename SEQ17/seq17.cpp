#include<bits/stdc++.h>
using namespace std;

#define maxN 500005
int n, q, a[maxN];
struct seg{
    long long val, lazy;
};
seg st[maxN * 4];

void init(int id, int l, int r){
    if (l == r){
        st[id].val = a[l];
        return;
    }

    int mid = (l + r)/2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
    st[id].val = st[id * 2].val + st[id * 2 + 1].val;
}

void update(int id, int l, int r, int i, int j,int x){
    if (r < i || j < l) return;
    if (i <= l && r <= j){
        st[id].val += (r - l + 1)*x;
        st[id].lazy = x;
        return;
    }

    int mid = (l + r)/2;
    if (st[id].lazy != -1){
        int t = st[id].lazy;
        st[id].lazy = 0;
        st[id * 2].val += (mid - l + 1)*t;
        st[id * 2 + 1].val += (r - mid)*t;
        st[id * 2].lazy += t;
        st[id * 2 + 1].lazy += t;
    }
    update(id * 2, mid, l, i, j, x);
    update(id * 2 + 1, mid + 1, r, i, j, x);
    st[id].val = st[id * 2].val + st[id * 2 + 1].val;
}

long long query(int id, int l, int r, int i,int j){
    if (r < i || j < l) return 0;
    if (i <= l && r <= j){
        return st[id].val;
    }

    int mid = (l + r)/2;
    if (st[id].lazy != -1){
        int t = st[id].lazy;
        st[id].lazy = 0;
        st[id * 2].val += (mid - l + 1)*t;
        st[id * 2 + 1].val += (r - mid)*t;
        st[id * 2].lazy += t;
        st[id * 2 + 1].lazy += t;
    }
    long long get1 = query(id * 2, l, mid, i, j);
    long long get2 = query(id * 2 + 1, mid + 1, r, i, j);
    return get1 + get2;
}

int main(){
    freopen("SEQ17.inp","r",stdin);
    freopen("SEQ17.out","w",stdout);
    cin >> n >> q;
    for (int i = 1; i <= n ; i++)
        cin >> a[i];

    init(1, 1, n);
    for (int i = 1; i <= q; i++){
        int type; cin >> type;
        if (type == 0){
            int x, y, z; cin >> x >> y >> z;
            update(1, 1, n, x, y, z);
        } else {
            int x, y; cin >> x >> y;
            cout << query(1, 1, n, x, y) << "\n";
        }
    }


    return 0;
}
