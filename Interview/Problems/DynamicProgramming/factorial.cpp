#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

vector< lli > factorial_numbers( 1001, 0 );

lli factorial( int n ){

    if( factorial_numbers[ n ] != 0 )
        return factorial_numbers[ n ];

    if( n > 1 )
        return (factorial_numbers[ n ] = ( n * factorial( n - 1 ) ) );

    return factorial_numbers[ n ] = 1 ;
}   

int main(){
    int n, t;
    cin >> t;
    factorial( 100 );
    while( t-- ){
        cin >> n;
        cout << n << "! = " << factorial( n ) << endl;
    }
    return 0;
}