#include <bits/stdc++.h>

using namespace std;

using lli = long long int;
set< lli > number_list;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli N;
    string Xi;
    cin >> N;
    for( lli i = 0; i < N; i++ ){
        cin >> Xi;
        if( Xi.size() <= 7 )
            number_list.insert( stoll( Xi ) );
    }

    for( lli i = 0; i < 1000001; i++ ){
        if( number_list.find( i ) == number_list.end() ){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}