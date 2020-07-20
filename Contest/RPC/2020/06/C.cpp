#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

int main() {
    lli m, n, a, res;
    cin >> m >> n >> a;
    res = n * m - a;
    if((a % m) == 0 or (a % n) == 0)
        cout << "1" << endl;
    else if((res % n) == 0 or (res % m) == 0) {
        cout << "2" << endl;
    } else {
        cout << "3" << endl;
    }
    return 0;
}