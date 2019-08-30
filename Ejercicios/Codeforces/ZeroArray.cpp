#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    lli n, v, ans = 0;
    vector< lli > numbers;
    cin >> n;
    for(int i = 0, v; i < n; i++){
        cin >> v;
        if( v != 0 )
            numbers.push_back( v );
    }
    
    sort( numbers.begin(), numbers.end() );

    for( auto v : numbers ){
        cout << v << " ";
    }
    cout << endl;
    for( int i = n - 1; i >= 1; i -= 2 ){
        lli a = numbers[ i ];
        lli b = numbers[ i - 1 ];
        numbers[ i ] = abs(a - b);
        numbers[ i - 1 ] = abs(a - b);
    }

    sort( numbers.begin(), numbers.end() );

    for( auto v : numbers ){
        cout << v << " ";
    }
    cout << endl;

    for( int i = n - 1; i >= 1; i -= 2 ){
        if( numbers[ i ] != 0 ){
            lli a = numbers[ i ];
            lli b = numbers[ i - 1 ];
            numbers[ i ] -= b;
            numbers[ i - 1 ] -= a;
        }
    }

    for( auto v : numbers ){
        cout << v << " ";
    }
    cout << endl;
    
    cout << "YES" << endl;
    return 0;
}