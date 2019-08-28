#include <bits/stdc++.h>

using namespace std;
int n;

vector< vector< int > > matrix;
vector< vector< int > > DP;

int max_sum( int i, int j ){

    if( j < 0 || j >= n )
        return INT_MIN;
    if( i == n - 1 )
        return matrix[ i ][ j ];

    if( DP[ i ][ j ] != INT_MIN )
        return DP[ i ][ j ];

    int A = max_sum( i + 1, j - 1 );
    int B = max_sum( i + 1, j );
    int C = max_sum( i + 1, j + 1 );

    return DP[ i ][ j ] =  max( {A, B, C} ) + matrix[ i ][ j ];
}

int main(){
    ios::sync_with_stdio( 0 );
    cout.tie( 0 );
    cin.tie( 0 );
    int t;
    cin >> t;
    while( t-- ){

        cin >> n;
        matrix.assign( n, vector< int >( n ) );
        DP.assign( n, vector< int >( n, INT_MIN ) );
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < n; j++ )
                cin >> matrix[ i ][ j ];
        }

        int ans = INT_MIN;
        for( int j = 0; j < n; j++)
            ans = max( ans, max_sum( 0, j ) );
        cout << ans << endl;
    }
    return 0;
}