#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

bool verify( lli middle, vector< lli > &numbers, lli k ){
    int n = numbers.size();
    for( int i = n / 2; i < n; i++){
        if( middle - numbers[ i ] > 0 )
            k -= middle - numbers[ i ];
    }
    return ( k >= 0 );
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli n, k, begin, end, middle;
    cin >> n >> k;
    vector< lli > numbers( n );
    for( int i = 0; i < n; i++ )
        cin >> numbers[ i ];

    sort( numbers.begin(), numbers.end() );
    //Binary search
    begin = numbers[ n / 2 ];
    end = begin + k;
    while( begin != end ){
        middle = ( begin + end + 1 ) / 2;
        if( verify( middle, numbers, k ) ){
            begin = middle;
        } else {
            end = middle - 1;
        }
    }

    cout << begin << endl;

    return 0;
}