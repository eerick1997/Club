#include <bits/stdc++.h>

using namespace std;

using vi = vector< int32_t >;
using board = vector< vi >;

bool check( board &Board, int32_t row, int32_t column ) {
    int32_t n = Board.size();
    for( int32_t i = 0; i < column; i++ )
        if( Board[ row ][ i ] )
            return false;
    
    for( int32_t i = row, j = column; i >= 0 and j >= 0; i--, j-- )
        if( Board[ i ][ j ] )
            return false;

    for( int32_t i = row, j = column; i < n and j >= 0; i++, j-- )
        if( Board[ i ][ j ] )
            return false;
    
    return true;
}

bool solve( board &Board, int32_t n, int32_t current_column ) {
    if( current_column == n )
        return true;
    for( int32_t row = 0; row < n; row++ ) {
        //We check if with the current information we can get a valid answer
        if( check( Board, row, current_column ) ) {
            //If is possible we set a queen let's try 
            Board[ row ][ current_column ] = 1;
            //Using recursive calls we set a queen and let's try to find another valid queen
            if( solve( Board, n, current_column + 1 ) )
                return true;
            //If we can't find a solution we backtrack
            Board[ row ][ current_column ] = 0;
        }
    }
    return false;
}

void print_board( board &Board ) {
    cout << endl;
    for( vi C : Board ) {
        cout << endl;
        for( int32_t cell : C ) 
            cout << cell << " ";
        
    }
    cout << endl;
}
int main() {
    
    int32_t n;
    cin >> n;
    board Board( n, vi( n, 0 ) );
    solve( Board, n, 0 );
    print_board( Board );
    return 0;
}