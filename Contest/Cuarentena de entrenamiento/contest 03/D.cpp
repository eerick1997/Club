#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

lli arr[ 600005 ], ST[ 2400005 ];

lli ans = 0, max_node;

void build( lli begin, lli end, lli position ) {
    max_node = max( max_node, position );
    if( begin == end ) {
        ST[ position ] = arr[ begin ];
        return;
    }
    lli middle = ( begin + end ) >> 1;
    build( begin, middle, position * 2 );
    build( middle + 1, end, position * 2 + 1);
    ST[ position ] = __gcd( ST[ 2 * position ], ST[ 2 * position + 1 ] );

}

void query( lli begin, lli end, lli left, lli right, lli GCD, lli position ) {
    if( end < left or right < begin )
        return;

    if( begin >= left and end <= right ){
        lli aux_pos = position;

        if( ST[ position ] % GCD == 0 )
            return;

        while( aux_pos <= max_node ) {
            if( ( ST[ 2 * aux_pos ] % GCD ) != 0 ) {
             if( ST[ 2 * aux_pos + 1 ] % GCD != 0 ){
                    ans += 2;
                    return;
                } else
                    aux_pos = 2 * aux_pos;
            } else {
                aux_pos = 2 * aux_pos + 1;
            }
        }
        ans++;
        return;
    }

    lli middle = ( begin + end ) >> 1;
    query( begin, middle, left, right, GCD, 2 * position );
    query( middle + 1, end, left, right, GCD, 2 * position + 1);
}

void update( lli begin, lli end, lli id, lli value, lli position ) {
    if( end < id or id < begin)
        return;

    if( begin == end and begin == id ) {
        ST[ position ] = value;
        do {
            position >>= 1;
            ST[ position ] = __gcd( ST[ 2 * position ], ST[ 2 * position + 1 ] );
        } while( position > 1 );
        return;
    }
    lli middle = ( begin + end ) >> 1;
    update( begin, middle, id, value, 2 * position );
    update( middle + 1, end, id, value, 2 * position + 1 );
}

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    lli n, q, type, l, r, GCD, id, y;
    cin >> n;

    for( lli i = 1; i <= n; i++ )
        cin >> arr[ i ];

    build( 1, n, 1 );

    cin >> q;
    for( lli i = 0; i < q; i++ ){
        ans = 0;
        cin >> type;
        if( type == 1 ) {
            cin >> l >> r >> GCD;
            query( 1, n, l, r, GCD, 1 );
            cout << ( ans > 1 ? "NO" : "YES" ) << endl;
        } else {
            cin >> id >> y;
            update( 1, n, id, y, 1 );
        }
    }
    return 0;
}