#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){

    double n, x, y, ans;
    cin >> n >> x >> y;
    ans = ( ceil(n * (y / 100) ) - x);
    cout << (  ans < 0 ? 0 : ans) << endl;
    return 0;
}