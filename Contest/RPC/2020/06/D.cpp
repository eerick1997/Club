#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

int r_bullseye, r_double_ring, r_single_ring, n_wedges;

int get_wedge(double x, double y) {
    double size, angle;
    size = 360 / n_wedges;
    angle = atan(x/y);
    for(int i = n_wedges, j = 1; i > 0; i--, j++) {
        if(size * i >= x and x <= size * (i + 2) and size * i >= y and y <= size * (i + 2))
            return j;
    }
    return 0;
}

int get_ring(double x, double y) {
    double r1 = r_double_ring + r_bullseye;
    double r2 = r1 + r_single_ring;
    if(x >= -r1 and x <= r1 and y >= -r1 and y <= r1){
        return 2;
    }
    if(x >= -r2 and x <= r2 and y >= -r2 and y <= r2)
        return 1;
    return 0;
}

double get_points(double x, double y) {
    if(x >= -r_bullseye and x <= r_bullseye and y >= -r_bullseye and y <= r_bullseye)
        return 50;
    return get_ring(x, y) * get_wedge(x, y);
}

int main() {
    int n_test_cases; 
    int n_darts;
    double x, y, ans = 0;

    cin >> n_test_cases;
    while(n_test_cases--) {
        ans = 0;
        cin >> n_wedges >> r_bullseye >> r_double_ring >> r_single_ring >> n_darts;
        while(n_darts--) {
            cin >> x >> y;
            ans += get_points(x, y);
        }
    }

    return 0;
}