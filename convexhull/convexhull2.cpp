#include<bits/stdc++.h>
using namespace std;

#define maxN 100005
struct point{
    int x, y;
};
vector <point> p;
map <pair<int, int>, int> mp;
int n, cnt, check[maxN];

bool cmp(point u, point v){
    if (u.x == v.x) return u.y < v.y;
    return u.x < v.x;
}

long long tichcheo(point a, point b, point c){
    return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x));
}

// vector <point> convexhull(vector <point> p){
//     vector <point> hull;
//     hull.push_back(p[0]);

//     for (int i = 1; i < p.size(); i++){
//         while (hull.size() >= 2 && tichcheo(hull[hull.size() - 2], hull.back(), p[i]) > 0){
//             hull.pop_back();
//         }
//         hull.push_back(p[i]);
//     }
//     for (int i = p.size() - 2; i >= 0; i--){
//         while (hull.size() >= 2 && tichcheo(hull[hull.size() - 2], hull.back(), p[i]) > 0){
//             hull.pop_back();
//         }
//         hull.push_back(p[i]);
//     }
//     if (hull.size() > 1) hull.pop_back();
//     return hull;
// }

vector<point> convexHull(vector<point> &args) {
    vector<point> hull;
    hull.push_back(args[0]);

    for (int i = 1; i < args.size(); i++) {
        while (hull.size() >= 2 && tichcheo(hull[hull.size() - 2], hull.back(), args[i]) > 0) {
            hull.pop_back();
        }
        hull.push_back(args[i]);
    }

    for (int i = args.size() - 2; i >= 0; i--) {
        while (hull.size() >= 2 && tichcheo(hull[hull.size() - 2], hull.back(), args[i]) > 0) {
            hull.pop_back();
        }
        hull.push_back(args[i]);
    }

    if (hull.size() > 1) hull.pop_back();
    return hull;
}

int main(){
    // freopen("CONVEXHULL.inp","r",stdin);
    // freopen("CONVEXHULL.out","w",stdout);
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        int u, v; cin >> u >> v;
        if (mp.count({u, v}) == 0){
            p.push_back({u, v});
        }
        mp[{u, v}]++;
    }
    n =  p.size();

    sort(p.begin(), p.end(), cmp);
    vector <point> hull = convexHull(p);
    cout << hull.size() << endl;
    for (point i: hull){
        cout << i.x << ' ' << i.y << endl;
    }

    cnt = hull.size();
    hull.push_back(hull[0]);
    for (int i = 0; i < hull.size() - 2; i++){
        if (tichcheo(hull[i], hull[i+1], hull[i+2]) == 0){
            check[i + 1] = 1;
            cnt--;
        }
    }
    cout << "\n";
    hull.pop_back();
    cout << cnt << "\n";
    for (int i = 0; i < hull.size(); i++){
        if (check[i] == 1)
            continue;
        else
            cout << hull[i].x << " " << hull[i].y << endl;
    }

    return 0;
}