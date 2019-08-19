#include <bits/stdc++.h>

using namespace std;

set< int > broken;
int main(){
    int n, v, channel;
    string s1, s2;
    cin >> n;
    while( n-- ){
        cin >> v;
        broken.insert( v );
    }

    cin >> channel;

    int offset = 0;
    while( true ){
        s1 = to_string( channel + offset );
        s2 = to_string( channel - offset );
        cout << "s1 " << s1 << endl;
        cout << "s2 " << s2 << endl;
        if( 
            all_of( s1.begin(), s1.end(), []( char c ){ return (broken.count( c -'0' ) == 0); }  ) or 
            all_of( s2.begin(), s2.end(), []( char c ){ return (broken.count( c -'0' ) == 0); }  )) break;
        offset++;
    }
    cout << offset << endl;
}