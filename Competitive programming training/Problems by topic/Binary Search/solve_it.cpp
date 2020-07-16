#include <bits/stdc++.h>

using namespace std;

double p = 0, q = 0, r = 0, s = 0, t = 0, u = 0;

double check(double x) {
    double t1 = p * exp(-x);
    double t2 = q * sin(x);
    double t3 = r * cos(x);
    double t4 = s * tan(x);
    double t5 = t * x*x;
    return t1 + t2 + t3 + t4 + t5 + u;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cout << fixed << setprecision(4);
    double begin, end, x;
    while(cin >> p >> q >> r >> s >> t >> u) {
        begin = 0, end = 1;
        for(int i = 0; i < 27; i++) {
            x = begin + ((end - begin) / 2);
            if(check(x) > 0)   
                begin = x;
            else
                end = x;
        }
        if((int)(check(x) * 1000) == 0)
            cout << x << endl;
        else 
            cout << "No solution\n";

    }
    return 0;
}