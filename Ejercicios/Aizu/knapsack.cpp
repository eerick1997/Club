#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli N;
lli v[ 1005 ];
lli w[ 10005 ];
lli DP[ 1005 ][ 10005 ];
bool visited[ 1005 ][ 10005 ];

lli max_sum( lli i, lli weight ){

    if( weight < 0 )
        return INT64_MIN;
    
    if( i >= N )
        return 0;
    
    if( visited[ i ][ weight ] )
        return DP[ i ][ weight ];

    visited[ i ][ weight ] = true;

    lli take = max_sum( i + 1, weight - w[ i ] ) + v[ i ];
    lli not_take = max_sum( i + 1, weight );
    lli take_the_same = max_sum( i, weight - w[ i ] ) + v[ i ];

    return DP[ i ][ weight ] = max( { take, not_take, take_the_same } );
}

int main(){
    lli W;
    cin >> N >> W;
    for( int i = 0; i < N; i++)
        cin >> v[ i ] >> w[ i ];
    
    cout << max_sum( 0, W ) << endl;

    return 0;
}