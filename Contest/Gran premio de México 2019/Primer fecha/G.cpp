#include <bits/stdc++.h>
using namespace std;

using lli = long long;
int main () {
    int T;
    cin >> T;
    lli x;
    for(int j = 1; j <= T; j++) {
        cin >> x;
        lli count = 0;
        
        for(lli n = 1; true; n++) {
            lli part1 = (n* (n + 1)) / 2;
            lli part2 = n + 1;

            if ((part1 + part2) > x) break; 

            double d = (double)(x - part1) / (double)part2;
            if (d - (long long)d == 0) count++;
        }
    
        cout<<"case "<<j<<": "<<count<<"\n";

    }

    return 0;
}