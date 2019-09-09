#include <bits/stdc++.h>

using namespace std;
int n, m;
vector< int > X;
vector< int > DP;
int solution( int index ){

    if( index >= n )
        return 0;
    
    if( DP[ index ] != -1 )
        return DP[ index ];
        
    int take = solution( index + m ) + X[ index ];
    int not_take = solution( index + 1 );

    return DP[ index ] = max( take, not_take );
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    cin >> n >> m;
    X.assign( n, 0 );
    DP.assign( n , -1 );
    for( int i = 0; i < n; i++ )
        cin >> X[ i ];

    if( m > n ){
        cout << 0 << endl; 
        return 0;
    }
    
    cout << solution( m ) << endl;
    return 0;
}