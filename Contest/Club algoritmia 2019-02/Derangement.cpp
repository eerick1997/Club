#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli n;
    cin >> n;
    vector< lli > numbers( n ), pairs;
    for( int i = 0; i < n; i++ ){
        cin >> numbers[ i ];
        if( ( i + 1 ) == numbers[ i ] )
            pairs.push_back( i + 1 );
    }
    lli count = ceil( ((double)pairs.size()) / 2.0);
    cout << count << endl;
    if( pairs.size() > 0 ){
        for( int i = 0; i < pairs.size() - 1; i += 2 ){
            cout << pairs[ i ] << " " << pairs[ i + 1 ] << endl;
            swap( numbers[ i ], numbers[ i + 1 ] );
        }
    }

    if( ( pairs.size() % 2 ) != 0 ){
        for( int i = 0; i < n; i++ ){
            if( numbers[ pairs[pairs.size() - 1] ] != (i + 1) && numbers[ i ] != pairs[ pairs.size() - 1 ]){
                cout << (i + 1) << " " << pairs[ pairs.size() - 1 ] << endl; 
                return 0;
            }
        }
    }
    return 0;
}