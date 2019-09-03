#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
const lli MAX = 100005;

lli heights[ 2 ][ MAX ];

lli DP[2][ MAX ];
lli visited[ 2 ][ MAX ];
lli N;

lli maxHeight( lli row, lli index ){
    
    if( index >= N )
        return 0;
    
    if( visited[ row ][ index ] )
        return DP[ row ][ index ];

    visited[ row ][ index ] = true;
    lli take = maxHeight( ( row == 0 ? 1 : 0 ), index + 1 ) + heights[ row ][ index ];
    lli not_take_r1 = maxHeight( 0 , index + 1 );
    lli not_take_r2 = maxHeight( 1 , index + 1 );

    return DP[ row ][ index ] = max( { take, not_take_r1, not_take_r2 } );
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    cin >> N;
    for( int j = 0; j < 2; j++ )
        for( int i = 0; i < N; i++ )
            cin >> heights[ j ][ i ];
    
    lli ans = max( maxHeight( 0, 0 ), maxHeight( 1, 0 ) );
    cout << ans << endl;

    return 0;
}