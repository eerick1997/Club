#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int n;
int LIS( int index, int last, vector< vector< int > > &DP, vector< int > &A){

    //Caso base 
    if( index >= n )
        return 0;

    if( last >= 0 && DP[ index ][ last ] != INT_MIN )
        return DP[ index ][ last ];
    
    int take = 0, not_take = 0;

    not_take = LIS( index + 1, last, DP, A );
    //Vamos a tomar como válido el valor si y solo si el i-ésimo elemento es mayor que el anterior
    if( A[ index ] > last )
        take = (LIS( index + 1, A[ index ], DP, A ) + 1);
    
    if( last >= 0 )
        return DP[ index ][ last ] = max( take, not_take );

    return max( take, not_take );
}

int main(){
    int t;
    cin >> t;
    while( t-- ){
        cin >> n;
        vector< vector< int > > DP( MAX, vector< int > ( MAX, INT_MIN ) );
        vector< int > A( MAX );
        for( int i = 0; i < n; i++ )
            cin >> A[ i ];
        cout << LIS( 0, INT_MIN, DP, A ) << endl;
    }
    
}