#include <bits/stdc++.h>

using namespace std;

set< int > broken;
int main(){
    int n, v, channel, ans = 0, Min = INT_MAX;
    bool flag;
    string s;
    cin >> n;
    while( n-- ){
        cin >> v;
        broken.insert( v );
    }

    cin >> channel;

    for( int i = 0; i <= 999; i++ ){
        flag = true;
        s = to_string( i );

        for( char c : s ){ 
            if( broken.count( c - '0' ) > 0)
                flag = false;
        }

        if( abs( i - channel ) <= Min && flag )
                Min = abs(i - channel), ans = i;

    }
    cout << Min << endl;
}