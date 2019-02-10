#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;


int main(){
    lli x, y, z;
    lli x1, y1, z1;
    lli a, b, c;
    lli a1, b1, c1;

    cin >> x >> y >> z;
    cin >> a >> b >> c;

    a1 = a - x;
    x1 = x - a;
    x = (x1 < 0) ? 0 : x1;
    a = (a1 < 0) ? 0 : a1;

    a1 = a - y;
    y1 = y - a;
    y = (y1 < 0) ? 0 : y1; 
    a = (a1 < 0) ? 0 : a1;

    b1 = b - y;
    y1 = y - b;
    y = (y1 < 0) ? 0 : y1; 
    b = (b1 < 0) ? 0 : b1;

    a1 = a - z;
    z1 = z - a;
    z = (z1 < 0) ? 0 : z1; 
    a = (a1 < 0) ? 0 : a1;

    b1 = b - z;
    z1 = z - b;
    z = (z1 < 0) ? 0 : z1; 
    b = (b1 < 0) ? 0 : b1;

    c1 = c - z;
    z1 = z - c;
    z = (z1 < 0) ? 0 : z1; 
    c = (c1 < 0) ? 0 : c1;

    if(x == 0 && y == 0 && z == 0)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;    

    return 0;
}