#include <bits/stdc++.h>

using namespace std;

using lli = long long int;
using node = pair< lli, lli >;
vector< lli > arr( 100005 );
vector< node > ST( 300005 );
vector< lli > aux( 4 );

void build( lli begin, lli end, lli position ) {
    if( begin == end ) {
        ST[ position ].first = arr[ begin ];
        ST[ position ].second = 0;
    } else {
        lli middle = ( begin + end ) >> 1;
        build( begin, middle, position * 2 );
        build( middle + 1, end, position * 2 + 1 );
        aux[ 0 ] = ST[ position * 2 ].first;
        aux[ 1 ] = ST[ position * 2 ].second;
        aux[ 2 ] = ST[ position * 2 + 1 ].first;
        aux[ 3 ] = ST[ position * 2 + 1 ].second;
        sort( aux.begin(), aux.end() );
        ST[ position ].first = aux[ 3 ];
        ST[ position ].second = aux[ 2 ];
    }
}

node query( lli begin, lli end, int l, int r, int position ){

    if( end < l or r < begin )
        return { 0, 0 };

    if( l <= begin and end <= r )
        return ST[ position ];

    int middle = ( begin + end ) / 2;
    node left_node = query( begin, middle, l, r, position * 2 );
    node right_node = query( middle + 1, end, l, r, position * 2 + 1 );
    aux[ 0 ] = left_node.first;
    aux[ 1 ] = left_node.second;
    aux[ 2 ] = right_node.first;
    aux[ 3 ] = right_node.second;
    sort( aux.begin(), aux.end() );
    return { aux[ 3 ], aux[ 2 ] };
}

void update( lli begin, lli end, lli id, lli v, lli position ){
    if( end < id or id < begin )
        return;
    if( begin == end and begin == id ){
        ST[ position ].first = v, ST[ position ].second = 0;
        do{
            position = position / 2;
            aux[ 0 ] = ST[ position * 2 ].first;
            aux[ 1 ] = ST[ position * 2 ].second;
            aux[ 2 ] = ST[ position * 2 + 1 ].first;
            aux[ 3 ] = ST[ position * 2 + 1 ].second;
            sort( aux.begin(), aux.end() );
            ST[ position ].first = aux[ 3 ], ST[ position ].second = aux[ 2 ];
        } while( position > 1 );
        return;
    }
    lli middle = ( begin + end ) >> 1;
    update( begin, middle, id, v, position * 2 );
    update( middle + 1, end, id, v, position * 2 + 1 );
}

void print() {
    for( int i = 0; i < 10; i++ ) {
        cout << "[ " << i << "] {" << ST[ i ].first << ", " << ST[ i ].second << " } " << endl;
    }
}
int main(){

    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    lli N, Q;
    cin >> N;
    for( lli i = 1; i <= N; i++ )
        cin >> arr[ i ];

    cin >> Q;

    build( 1, N, 1 );
    for( lli i = 0; i < Q; i++ ) {
        char OP;
        int x, y;
        cin >> OP >> x >> y;
        if( OP == 'Q' ) {
            node ans = query( 1, N, x, y, 1 );
            cout << ans.first + ans.second << endl;
        } else
            update( 1, N, x, y, 1 );
    }
}