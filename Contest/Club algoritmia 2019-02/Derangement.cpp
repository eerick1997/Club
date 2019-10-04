#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli n;
    cin >> n;
    vector< lli > numbers( n );

    vector< bool > visited( n, false );
    for( int i = 0; i < n; i++ )
        cin >> numbers[ i ];

    lli count = 0;
    vector< lli > pairs;
    for( int i = 0; i < n; i++ ){
        if( numbers[ i ] == (i + 1) ){
            count++;
            pairs.push_back( numbers[ i ] );
        }
    }
    //
    if( (count % 2) == 0 ){
        cout << (count / 2) << endl;
        for( int i = 0; i < pairs.size(); i += 2 )
            cout << pairs[ i ] << " " << pairs[ i + 1 ] << endl;
    } else {
        cout << (count / 2) + 1 << endl;
        for( int i = 0; i < pairs.size() - 1; i += 2 )
            cout << pairs[ i ] << " " << pairs[ i + 1 ] << endl;

        for( int i = 0; i < n; i++ ){
            if( numbers[ i ] != (i + 1) && numbers[ i ] != pairs[ pairs.size() - 1 ]){
                cout << numbers[ i ] << " " << pairs[ pairs.size() - 1 ] << endl;
                break;
            }
        }

    }

    

    
    
    return 0;
}