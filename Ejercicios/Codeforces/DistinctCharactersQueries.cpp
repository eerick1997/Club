#include <bits/stdc++.h>

using namespace std;
vector< set< int > > bucket( 26 );
string s;

inline int countDifferentCharacters( int l, int r ){
    int count = 0;
    l--, r--;
    for( int i = 0; i < 26; i++ ){
        auto it = bucket[ i ].lower_bound( l );
        if( it != bucket[ i ].end() && (*it) <= r )
            count++;
    }
    return count;
}

inline void updateCharacter( char c, int position ){
    position--;
    bucket[ s[ position ] - 'a' ].erase( position );
    s[ position ] = c;
    bucket[ s[ position ] - 'a' ].insert( position );
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    char c;
    int queries, query, l, r;
    cin >> s >> queries;
    for( int i = 0; i < s.size(); i++ )
        bucket[ s[ i ] - 'a' ].insert( i );

    for( int i = 0; i < queries; i++ ){
        cin >> query >> l;
        if( query == 1 ){
            cin >> c;
            updateCharacter( c, l );
        } else {
            cin >> r;
            cout << countDifferentCharacters(l, r) << endl;
        }
    }

    return 0; 
}