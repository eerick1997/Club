 #include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli bucket[ 100005 ];
lli DP[ 100005 ];
bool visited[ 100005 ];
lli n;
int MAX = -1;

lli max_sum( int index ){

    if( index >= MAX + 1)
        return 0;
    
    if( visited[ index ] )
        return DP[ index ];
    visited[ index ] = true;    
    //Tomamos el elemento actual
    lli take = max_sum( index + 2 ) + ( bucket[ index ] * index );
    //Nos saltamos el elemento actual
    lli not_take = max_sum( index + 1 );

    return DP[ index ] = max( take, not_take );
}

int main(){
    cin >> n;
    for( int i = 0, v; i < n; i++){
        cin >> v;
        MAX = max( MAX, v );
        //Generamos nuestra cubeta
        bucket[ v ]++;
    }
    
    cout << max_sum( 1 ) << endl;
    return 0;
}