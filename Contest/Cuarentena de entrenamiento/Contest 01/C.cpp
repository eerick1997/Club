#include <bits/stdc++.h>

using namespace std;

using lli = long long int;
using point = pair< lli, lli >;

lli cross( const point p1, const point p2 ) {
    return p1.first * p2.second - p1.second * p2.first;
}

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    vector< set< lli > > ans;
    lli mountains;
    vector< point > points;
    point Q( 0, 0 );
    points.push_back( Q );
    cin >> mountains;
    ans.resize( mountains + 1, {} );
    for( lli i = 0, ui, di; i < mountains; i++ ) {
        cin >> ui >> di;
        Q.first += ui, Q.second += ui;
        points.push_back( Q );
        Q.first += di, Q.second += -di;
    }

    for( lli current = points.size() - 1; current >= 0; current-- ) {
        point p1 = points[ current ];
        point p2 = points[ current - 1 ];
        ans[ current ].insert( current );
        for( lli i = current - 2; i >= 0; i-- ) {
            point &p = points[ i ];
            lli position = cross( { p2.first - p1.first, p2.second - p1.second }, { p.first - p1.first, p.second - p1.second } );
            cout << " - " << position << endl;
            if( position <= 0 ) {
                ans[ current ].insert( i + 1 );
                p2 = p;
            }
        }
    }
    cout << 0 << endl;
    for( lli i = 1; i < mountains; i++ ) {
        cout << ans[ i ].size() << " ";
        for( auto e : ans[ i ] )
            cout << e << " "; 
        cout << endl;
    }

    return 0;
}