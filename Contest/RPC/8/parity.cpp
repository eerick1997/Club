#include<bits/stdc++.h>

using namespace std;

unordered_map< char, bool > bucket;

int main(){
    string s;
    char c;
    while( (c = getchar()) != '\n' ){
        bucket[ c - 'a'] = !bucket[ c - 'a' ];
    }

    int ans = 0;
    bool a = all_of( bucket.begin(), bucket.end(), []( auto i ){ return i.second; } );
    bool b = all_of( bucket.begin(), bucket.end(), []( auto i ){ return !i.second; } );
    
    if( a )
        cout << 1 << endl;
    else if( b )
        cout << 0 << endl;
    else 
        cout << 2 << endl;
    
    return 0;
}