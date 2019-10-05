#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

/**
 * Consider Golbach conjeture
 * -> All number even can be written as a sum of two prime numbers
 * -> All number greater to 2 can ve written as a sum of three prime numbers
 * -> If the number is prime you only need one number
 * **/
bool isPrime( lli n ){
    for( lli d = 2; d * d <= n; d++ )
        if( ( n % d ) == 0 )
            return false;
    return true;
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli n;
    cin >> n;

    if( isPrime( n ) )
        cout << 1 << endl;
    else if( !( n & 1 ) ){
        cout << 2 << endl;
    } else {
        
        cout << ( isPrime( n - 2 ) ? 2 : 3 ) << endl;
    }
    return 0;
}