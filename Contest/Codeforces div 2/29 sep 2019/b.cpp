#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long int lli;
typedef vector< lli > vii;

const lli emptyCell = 0;
const lli fillCell = 1;
const lli none = -1;

lli C[ 1005 ][ 1005 ];

void Combinatorics( lli n, lli k ){
    
    for( lli i = 0; i <= n; i++ ){
        for( lli j = 0; j <= min(i, k); j++ ){
            if( j == 0 || j == i )
                C[ i ][ j ] = 1;
            else 
                C[ i ][ j ] = (C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ]) % MOD;
        }
    }
}

int main(){
    lli height, width;
    vector< vii > matrix;    
    cin >> height >> width;
    matrix.assign( height + 2, vii( width + 2, none ));

    Combinatorics( 1001, 1001 );

    for( int i = 1, v; i <= height; i++ ){
        cin >> v;
        if( v > 0 ){
            for( int j = 1; j <= v; j++ ){
                matrix[ i ][ j ] = fillCell;
            }
            matrix[ i ][ v + 1 ] = emptyCell;
        } else 
            matrix[ i ][ 1 ] = emptyCell;
    }

    for( int i = 1, v; i <= width; i++ ){
        cin >> v;
        if( v > 0 ){
            for( int j = 1; j <= v; j++ ){
                if( matrix[ j ][ i ] == fillCell || matrix[ j ][ i ] == none )
                    matrix[ j ][ i ] = fillCell;
                else{
                    cout << 0 << endl;
                    return 0;
                } 

            }
            matrix[ v + 1 ][ i ] = emptyCell;
        } else 
            matrix[ 1 ][ i ] = emptyCell;
    }

    lli sumEmptyCells = 0;
    for( int i = 1; i <= height; i++ ){
        for( int j = 1; j <= width; j++ ){
            if( matrix[ i ][ j ] == none )
                sumEmptyCells++;
            cout << matrix[ i ][ j ] << "\t";
        }
        cout << endl;
    }

    lli ans = 0;
    cout << endl << sumEmptyCells << endl;
    for( int i = 0; i <= sumEmptyCells - 30; i++ ){
        ans += ( C[ sumEmptyCells ][ i ] % MOD);
    }

    cout << ans << endl;

    return 0;
}