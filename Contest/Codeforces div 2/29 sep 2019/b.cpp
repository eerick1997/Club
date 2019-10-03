#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long int lli;
typedef vector< lli > vii;

const lli emptyCell = 0;
const lli fillCell = 1;
const lli none = -1;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli height, width;
    vector< vii > matrix;    
    cin >> height >> width;
    matrix.assign( height + 2, vii( width + 2, none ));

    //Columns
    for( int i = 1, v; i <= height; i++ ){
        cin >> v;
        for( int j = 1; j <= v; j++ ){
            matrix[ i ][ j ] = fillCell;
        }
        matrix[ i ][ v + 1 ] = emptyCell; 
    }

    //row
    for( int i = 1, v; i <= width; i++ ){
        cin >> v;
        for( int j = 1; j <= v; j++ ){
            lli &cell = matrix[ j ][ i ];
            if( cell == fillCell || cell == none )
                cell = fillCell;
            else{
                cout << 0 << endl;
                return 0;
            }
        }
        lli &cell = matrix[ v + 1 ][ i ];
        if( cell == emptyCell || cell == none )
            cell = emptyCell;
        else {
            cout << 0 << endl;
            return 0;
        }
    }

    lli sumEmptyCells = 0;
    lli ans = 1;
    for( int i = 1; i <= height; i++ ){
        for( int j = 1; j <= width; j++ ){
            if( matrix[ i ][ j ] == none )
                ans = ( (ans * 2) % MOD );
        }
    }

    cout << ans << endl;

    return 0;
}