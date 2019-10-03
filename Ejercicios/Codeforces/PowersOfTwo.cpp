#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    
    lli n, k, count = 0, number = 0;
    map< lli, lli > powersOfTwo;
    cin >> n >> k;
    for( int i = 0; i <= 30; i++ ){
        if( ( (n >> i) & 1 ) == 1 )
            powersOfTwo[ 1 << i ]++;
    }

    count = powersOfTwo.size();
    
    if( count > k || k > n )
        cout << "NO" << endl;
    else {
        while( count < k ){
            //cout << count << " map.first = " << powersOfTwo.rbegin() -> first << ", map.second = " << powersOfTwo.rbegin() -> second << endl;
            if( (powersOfTwo.rbegin() -> second ) > 0 && ( powersOfTwo.rbegin() -> first ) > 1){
                
                ( powersOfTwo.rbegin() -> second )--;

                powersOfTwo[ (powersOfTwo.rbegin() -> first) >> 1 ] += 2;

                if( powersOfTwo.rbegin() -> second == 0 )
                    powersOfTwo.erase( powersOfTwo.rbegin() -> first );

                count++;
            }
        }
        cout << "YES" << endl;
        for( auto powerOfTwo : powersOfTwo )
            for( int i = 0; i < powerOfTwo.second; i++)
                cout << powerOfTwo.first << " ";
        cout << endl; 
    }


    return 0;
}