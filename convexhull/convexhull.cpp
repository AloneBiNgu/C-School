#include <bits/stdc++.h>

using namespace std;

struct Points {
    int x, y;
}

int FindPoint(vector<Points> &args) {
    int ans = 0;
    for (int i = 1; i < args.size(); i++) {
        if (args[i].y < args[ans].y || args[i].y == args[ans].y && args[i].x < args[ans].x) {
            ans = i;
        }
    }
    swap(args[0], args[ans]);
    
}

int main() {

    return 0;
}