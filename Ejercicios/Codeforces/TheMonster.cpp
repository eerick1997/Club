#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli extendedEuclidean( lli a, lli b, lli c, lli d ){

}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli a, b, c, d, Rick = -1, Morty = 0;

    cin >> a >> b >> c >> d;
    
    for( int i = 0; i <= 100; i++ ){
        for( int j = 0; j <= 100; j++ ){
            Rick = b + (a * i);
            Morty = d + (c * j);
            if( Rick == Morty ){
                cout << Rick << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}