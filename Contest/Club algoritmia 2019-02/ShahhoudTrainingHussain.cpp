#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli K, P, N, T, MAX = INT64_MAX, MIN = INT64_MIN, sum = 0;
    cin >> T;
    while( T-- ){
        cin >> K >> P >> N;
        cout << ( ( (K - P) * N ) < 0 ? 0 : ( (K - P) * N ) ) << endl;
    }
    return 0;
}
