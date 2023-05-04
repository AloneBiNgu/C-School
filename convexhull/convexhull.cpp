#include<bits/stdc++.h>
using namespace std;

int n;
struct point{
    int x, y;
};
vector <point> p;

int main(){
    freopen("CONVEXHULL.inp","r",stdin);
    freopen("CONVEXHULL.out","w",stdout);
    cin >> n;
    p.resize(n);
    for (int i = 0 ; i < n ; i++){
        cin >> p[i].x >> p[i].y;
        }

    return 0;
}
