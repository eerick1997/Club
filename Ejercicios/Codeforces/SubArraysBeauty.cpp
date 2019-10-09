#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int n;
vector< int > A;

bool isSet( int a, int i ){
    return ( a & (1 << i) );
}

lli getBeauty(){
    lli ans = 0;
    for( int bitI = 0; bitI < 30; bitI++ ){
        int count = 0;
        lli total = 0;
        for( int i = 0; i < n; i++ ){
            if( isSet( A[ i ], bitI ) )
                count++;
            else 
                count = 0;

            total += count;
        }
        ans += total * ( 1 << bitI );
    }
    return ans;
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    int T;
    cin >> T;
    while( T-- ){
        cin >> n;
        A.assign( n, 0 );
        for( int i = 0; i < n; i++ )
            cin >> A[ i ];
        cout << getBeauty() << endl;
    }
    return 0;
}