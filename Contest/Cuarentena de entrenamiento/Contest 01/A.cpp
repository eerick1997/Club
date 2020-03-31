#include <bits/stdc++.h>

using namespace std;

using lli = long long int;
set< string > words;
vector< lli > size_word( 5005, 0 );

bool areEqual( string &s ){
    for( int i = 0, j = s.size() - 1; i < s.size(); i++, j-- )
        if( s[ i ] != s[ j ])
            return false;
    return true;
}

void getSubstrings( string &s ){
    string str;
    for( int i = 0; i < s.size(); i++ ){
        str.clear();
        for( int j = i; j < s.size(); j++ ){
            str += s[ j ];
            if( areEqual( str ) ) {
                words.insert( str );
                size_word[ str.size() ]++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli N, ans = 0;
    string s;
    cin >> N >> s;
    getSubstrings( s );
    for( auto e : words )
        ans = max( ans, (lli)e.size() );

    cout << ans << endl;
    cout << size_word[ ans ] << endl;
    return 0;
}