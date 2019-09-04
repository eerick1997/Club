#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

vector< lli > X;
lli C, N, t;

lli check( lli middle ){
    lli last = 0;
    lli count = 1;
    for( lli i = 1; i < N; i++ ){
        if( ( X[ i ] - X[ last ] ) >= middle )
            count++, last = i;
    }
    return count;
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli begin, end, ans;
    cin >> t;
    while( t-- ){
        cin >> N >> C;
        X.resize( N );
        for( lli i = 0; i < N; i++ )
            cin >> X[ i ];

        sort( X.begin(), X.end() );

        begin = 1, end = INT64_MAX, ans = 0; 
        while( begin <= end ){
            lli middle = ( begin + end ) >> 1;
            if( check( middle ) >= C )
                begin = middle + 1, ans = middle;
            else 
                end = middle - 1;
        }
        cout << ans << endl;
    }
    return 0;
}