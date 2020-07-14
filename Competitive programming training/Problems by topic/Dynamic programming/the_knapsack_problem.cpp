#include <bits/stdc++.h>

using namespace std;
struct item {
    int size;
    int value;
    item() : size(0), value(0){}
};

vector< item > items;
int64_t DP[ 2005 ][ 2005 ];

int64_t solve( int item_position, int capacity ) {

    if( capacity < 0 )
        return -1e5;

    if( item_position == items.size() )
        return 0;

    if( DP[capacity][item_position] != 0 )
        return DP[capacity][item_position];
    
    int64_t not_take = solve( item_position + 1, capacity );
    int64_t take = solve( item_position + 1, capacity - items[ item_position ].size ) + items[ item_position ].value;

    return DP[ capacity ][ item_position ] = max( take, not_take );
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int capacity, n_items;
    cin >> capacity >> n_items;
    items.resize( n_items );
    for( int i = 0; i < n_items; i++ )
        cin >> items[i].size >> items[i].value;
    cout << solve( 0, capacity ) << endl;
    return 0;
}