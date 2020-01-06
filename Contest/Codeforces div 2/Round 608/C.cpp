#include <bits/stdc++.h>

using namespace std;
typedef pair< int64_t, int64_t > pll;

int main() {
    int32_t n, Q1, Q2, Q3, Q4;
    int64_t Sx, Sy, Xi, Yi;
    vector< set< pll >> quadrant( 4 );

    cin >> n >> Sx >> Sy;
    cout << endl << endl;
    for( int i = 0; i < n; i++ ){
        cin >> Xi >> Yi;
        Xi += Sx, Yi += Sy;
        cout << Xi << " " << Yi << endl;
        if( Xi > Sx && Yi > Sy )
            quadrant[ 0 ].insert( { Xi, Yi } );
        else if( Xi < Sx && Yi > Sy )
            quadrant[ 1 ].insert( { Xi, Yi } );
        else if( Xi < Sx && Yi < Sy )
            quadrant[ 2 ].insert( { Xi, Yi } );
        else
            quadrant[ 3 ].insert( { Xi, Yi } );
    }

    Q1 = quadrant[ 0 ].size() + quadrant[ 1 ].size();
    Q2 = quadrant[ 1 ].size() + quadrant[ 2 ].size();
    Q3 = quadrant[ 2 ].size() + quadrant[ 3 ].size();
    Q4 = quadrant[ 3 ].size() + quadrant[ 0 ].size();
    cout << endl << endl;
    if( max( {Q1, Q2, Q3, Q4} ) == Q1 ) {
        cout << Q1 << endl;
        cout << Sx << " " << Sy + 1 << endl;
    } else if( max( {Q1, Q2, Q3, Q4} ) == Q2 ) {
        cout << Q2 << endl;
        cout << Sx - 1 << " " << Sy << endl;
    } else if( max( {Q1, Q2, Q3, Q4} ) == Q3 ) {
        cout << Q3 << endl;
        cout << Sx << " " << Sy - 1 << endl;
    } else if( max( {Q1, Q2, Q3, Q4} ) == Q4 ) {
        cout << Q4 << endl;
        cout << Sx + 1 << " " << Sy << endl;
    }
    return 0;
}