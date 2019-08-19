#include<bits/stdc++.h>

using namespace std;

unordered_map< char, bool > bucket;

int main(){
    string s;
    cin >> s;
    for( char c : s )
        bucket[ c - 'a' ] = ! bucket[ c - 'a' ];

    int ans = 0;
    bool first = true;
    bool second = true;
    //All are true?
    for( auto e : bucket )
        first &= e.second;
    for( auto e : bucket )
        second &= !e.second;

    
    if( first )
        cout << 1 << endl;
    else if( second )
        cout << 0 << endl;
    else 
        cout << 2 << endl;
    
    return 0;
}