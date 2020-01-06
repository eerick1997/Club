#include <bits/stdc++.h>

using namespace std;
int32_t length;
vector< int32_t > indexes;

void one_color( string &str, char color, char opposite, int32_t begin, int32_t end ){
    for( int32_t i = begin; i < end; i++ ){
        if( str[ i ] == color )
            continue;
        str[ i ] = color;
        indexes.push_back( i );
        str[ i + 1 ] = ( str[ i + 1 ] == color ) ? opposite : color;
    }
}

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    string str;
    char c, not_c;
    int32_t count_w = 0, count_b = 0;
    cin >> length >> str;
    for( char ch : str ) {
        if( ch == 'W' ) count_w++;
        else count_b++;
    }

    if( str[ 0 ] == 'W' )
        c = 'W', not_c = 'B';
    else
        c = 'B', not_c = 'W';

    one_color( str, c, not_c, 1, length - 1 );

    if( str[ length - 1 ] == 'W' )
        c = 'W', not_c = 'B';
    else
        c = 'B', not_c = 'W';

    one_color( str, c, not_c, 0, length - 2 );

    if( ( count_w & 1 ) && ( count_b & 1 ) )
        cout << -1 << endl;
    else {
        cout << indexes.size() << endl;
        for( int32_t index : indexes )
            cout << index + 1 << " ";
    }
    return 0;
}