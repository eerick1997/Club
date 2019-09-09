#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > DP;
string S, T;
int s, t;

int LCS( int index_s, int index_t ){
    //Si ya no hay caracteres que analizar terminamos las recursiones
    if( index_s >= s || index_t >= t )
        return 0;
    //Nuestra ''bandera'' es el valor de -1 ya que nunca nos devolverá ese valor la función
    if( DP[ index_s ][ index_t ] != INT_MIN )
        return DP[ index_s ][ index_t ];
    
    if( S[ index_s ] == T[ index_t ] ){
        DP[ index_s ][ index_t ] = LCS( index_s + 1, index_t + 1) + 1;
        return ( DP[ index_s ][ index_t ] );
    }
    
    int move_S = LCS( index_s + 1, index_t );
    int move_T = LCS( index_s, index_t + 1 );
    
    DP[ index_s ][ index_t ] = max( move_S, move_T );
    return ( DP[ index_s ][ index_t ] );
}

int main(){
    int test;
    cin >> test;
    while( test-- ){
        DP.assign( 105, vector<int>( 105, INT_MIN ) );
        cin >> s >> t;
        cin >> S >> T;
        cout << LCS( 0, 0 ) << endl;
    }

    return 0;
}