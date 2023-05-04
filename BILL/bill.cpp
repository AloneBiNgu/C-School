#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 5;

struct Point {
    double x, y;
} args[maxN];

int n;

long double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

long double distanceToLine(Point p, Point a, Point b) {
    double A = p.x - a.x;
    double B = p.y - a.y;
    double C = b.x - a.x;
    double D = b.y - a.y;

    double dot = A * C + B * D;
    double len_sq = C * C + D * D;
    double param = dot / len_sq;

    double xx, yy;

    if (param < 0) {
        xx = a.x;
        yy = a.y;
    }
    else if (param > 1) {
        xx = b.x;
        yy = b.y;
    }
    else {
        xx = a.x + param * C;
        yy = a.y + param * D;
    }

    double dx = p.x - xx;
    double dy = p.y - yy;
    return sqrt(dx * dx + dy * dy);
}

double minDistance(Point p, Point polygon[], int n) {
    double minDist = distanceToLine(p, polygon[0], polygon[n - 1]);

    for (int i = 1; i < n; i++) {
        double dist = distanceToLine(p, polygon[i], polygon[i - 1]);
        if (dist < minDist) {
            minDist = dist;
        }
    }

    bool inside = true;
    for (int i = 0; i < n; i++) {
        double dist = distance(p, polygon[i]);
        if (dist > minDist) {
            inside = false;
            break;
        }
    }

    if (inside) {
        minDist = min(distance(p, polygon[0]), distance(p, polygon[n - 1]));
        for (int i = 1; i < n - 1; i++) {
            double dist = distanceToLine(p, polygon[i], polygon[i + 1]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }

    return minDist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("bill.inp", "r", stdin);
        freopen("bill.out", "w", stdout);
    #endif
    
    cin >> n;

    Point bill;
    cin >> bill.x >> bill.y;

    for (Point &a : args) {
        cin >> a.x >> a.y;
    }
    
    long double minDist = minDistance(bill, args, n);
    cout << fixed << setprecision(4) << minDist << endl;

    return 0;
}
