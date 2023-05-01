// #include <bits/stdc++.h>

// using namespace std;

// struct Points {
//     long double x, y;
// };

// int n;
// Points bill;

// bool ccw(Points A, Points B, Points C) {
//     return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (C.x - A.x) * (B.y - A.y) > 0;
// }

// vector<Points> convexHull(vector<Points> &points) {
//     sort(points.begin(), points.end(), [](Points a, Points b) {
//         if (a.x != b.x) return a.x < b.x;
//         return a.y < b.y;
//     });

//     vector<Points> hull;
//     hull.push_back(points[0]);
    
//     for (int i = 1; i < points.size(); i++) {
//         while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), points[i])) {
//             hull.pop_back();
//         }
//         hull.push_back(points[i]);
//     }

//     for (int i = points.size() - 2; i >= 0; i--) {
//         while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), points[i])) {
//             hull.pop_back();
//         }
//         hull.push_back(points[i]);
//     }

//     if (hull.size() > 1) hull.pop_back();
//     return hull;
// }

// long double Dis(Points &a, Points &b) {
//     return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
// }

// Points TrungDiem(Points &a, Points &b) {
//     Points m;
//     m.x = (a.x + b.x) / 2;
//     m.y = (a.y + b.y) / 2;
//     return m;
// }

// void Process(vector<Points> &hull) {
//     long double ans = INT_MAX;

//     for (int i = 0; i < hull.size(); i++) {
//         cout << "Bill: " << bill.x << " " << bill.y << "\n";
//         cout << "Hull: " << hull[i].x << " " << hull[i].y << "\n";
//         cout << Dis(hull[i], bill) << "\n";
//         cout << "\n";
//     }
//     // cout << fixed << setprecision(4) << ans << "\n";
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     // freopen("bill.inp", "r", stdin);
//     // freopen("bill.out", "w", stdout);

//     cin >> n >> bill.x >> bill.y;
//     vector<Points> args(n);

//     for (int i = 0; i < n; i++) {
//         cin >> args[i].x >> args[i].y;
//     }

//     auto Hull = convexHull(args);
//     Process(Hull);
//     return 0;
// }

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

// Tính khoảng cách giữa hai điểm
double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Tính khoảng cách từ một điểm đến một đường thẳng
double distanceToLine(Point p, Point a, Point b) {
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

// Tìm khoảng cách nhỏ nhất từ một điểm ngoài đa giác đến đa giác đó
double minDistance(Point p, Point polygon[], int n) {
    double minDist = distanceToLine(p, polygon[0], polygon[n - 1]);

    for (int i = 1; i < n; i++) {
        double dist = distanceToLine(p, polygon[i], polygon[i - 1]);
        if (dist < minDist) {
            minDist = dist;
        }
    }

    // Nếu điểm ngoài đa giác nằm bên trong đa giác
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
    Point p = { -3910, 5301 };
    Point polygon[] = {
        { 1996, 3481 },
        { 1272, 4301 },
        { -1603, 3992 },
        { -2910, 175 },
        {-2156, -3213},
        {-656, -4658},
        {1859, -3679}
    };
    int n = sizeof(polygon) / sizeof(polygon[0]);

    double minDist = minDistance(p, polygon, n);
    cout << "Minimum distance: " << minDist << endl;

    return 0;
}
