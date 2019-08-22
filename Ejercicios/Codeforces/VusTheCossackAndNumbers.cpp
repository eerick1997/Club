#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio( 0 );
    cout.tie( 0 );
    cin.tie( 0 );
    int n;
    int sum = 0;
    cin >> n;
    vector< double > A( n );
    vector< int > ans( n );
    for( int i = 0; i < n; i++ ){
        cin >> A[ i ];
        ans[ i ] = ( A[ i ] );
        sum += ans[ i ];
    }
    if( sum != 0 ){
        for( int i = 0; i < n; i++){
            if( sum > 0 ){
                if( ( ans[ i ] - A[ i ] != 0 ) ){
                    if( A[ i ] < 0 )
                        ans[ i ]--, sum--;
                }
            } else if( sum < 0 ){
                if( ( ans[ i ] - A[ i ] != 0 ) ){
                    if( A[ i ] > 0 )
                        ans[ i ]++, sum++;
                }
            }
        }
    }

    for( auto m : ans )
        cout << m << " ";
    cout << endl;


    return 0;
}