#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
int T, n;
vector< int > indexes[ 200005 ];
vector< int > DP, colors;
lli getMinimumJumps( int index ){
    
    if( index >= n )
        return 0;
    
    if( DP[ index ] != -1 )
        return DP[ index ];

    int moveNext = getMinimumJumps( index + 1 ) + 1;
    auto it = upper_bound( indexes[ colors[ index ] ].begin(), indexes[ colors[ index ] ].end(), index );
    int moveNextSameColor = INT_MAX;

    if( it != indexes[ colors[ index ] ].end() )
        moveNextSameColor = getMinimumJumps( (*it) ) + 1;
    
    return ( DP[ index ] = min( moveNext, moveNextSameColor ) );
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    cin >> T;
    while( T-- ){
        cin >> n;
        DP.assign( n, -1 );
        colors.assign( n, 0 );

        for( int i = 0; i < 200005; i++ )
            indexes[ i ].clear();

        for( int i = 0; i < n; i++ ){
            cin >> colors[ i ];
            indexes[ colors[ i ] ].push_back( i );
        }
        cout << (getMinimumJumps( 0 ) - 1) << endl;
    }
    return 0;
}