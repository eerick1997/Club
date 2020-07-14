#include <bits/stdc++.h>

using namespace std;

vector< int > DP( 4005, -1 );
vector< int > cuts( 3 );

int solve(int current, int n_cuts) {

    if( current == 0 )
        return n_cuts;

    if( current < 0 )
        return 0;
    
    if( DP[ current ] != -1 )
        return DP[ current ];

    int A = solve(current - cuts[0], n_cuts + 1);
    int B = solve(current - cuts[1], n_cuts + 1);
    int C = solve(current - cuts[2], n_cuts + 1);
    
    return DP[ current ] = max( {A, B, C} );
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie( nullptr );
    cin.tie( nullptr );
    int ribbon_length;
    cin >> ribbon_length >> cuts[ 0 ] >> cuts[ 1 ] >> cuts[ 2 ];
    sort( begin(cuts), end(cuts) );
    cout << solve(ribbon_length, 0) << endl;   
    return 0;
}