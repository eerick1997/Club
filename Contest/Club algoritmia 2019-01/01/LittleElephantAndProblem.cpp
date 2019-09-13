#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
vector< lli > numbers, aux;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli n, ans = 0;
    cin >> n;
    numbers.assign(n, 0);
    aux.assign(n, 0);
    for( int i = 0, v; i < n; i++ ){
        cin >> v;
        numbers[ i ] = v;
        aux[ i ] = v;
    }

    sort( aux.begin(), aux.end() );
    int c = 0;
    for( int i = 0; i < n; i++ ){
        if( aux[ i ] != numbers[ i ] )
            c++;
    }
 
    
    cout << ( ( c <= 2 ) ? "YES" : "NO" ) << endl;
}