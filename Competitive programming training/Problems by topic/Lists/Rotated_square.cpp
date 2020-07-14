#include <bits/stdc++.h>

using namespace std;

int count( int n, int m, vector<string> &big, vector<string> &small ) {
    bool flag;
    int ans = 0;
    for( int i = 0; i < n - m; i++ ) {
        for( int j = 0; j < n - m; j++ ) {
            flag = true;
            for( int k = 0; k < m; k++ ) {
                for( int l = 0; l < m; l++ ) {
                    if( big_square[ i + k ][ j + l ] != small_square[ k ][ l ] )
                        flag = false;
                }
            }
            if( flag )  
                ans++;
        }
    }
    return ans;
}

vector< string > rotate( int m, vector< string > &small ){
    vector< vector< char > > rot_small( m, vector<char>( m ) );
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ) {
            
        }
    }
    
}


int main() {
    int dim_big_square, dim_small_square;   
    vector< vector< char > > big_square;
    vector< vector< char > > small_square;
    string buffer;
    while( cin >> dim_big_square >> dim_small_square and dim_small_square and dim_small_square ) {
        big_square.resize( dim_big_square, vector<char>( dim_big_square ) );
        small_square.resize( dim_small_square, vector< char >( dim_small_square ) );

        for( int i = 0; i < dim_big_square; i++ ) {
            cin >> buffer;
            
            for( int j = 0; j < dim_big_square; j++ ) 
                big_square[ i ][ buffer[ j ] ];
        }
    
        for( int i = 0; i < dim_small_square; i++) {
            cin >> buffer;
        
            for( int j = 0; j < dim_small_square; j++ ) 
                small_square[ i ][ buffer[ j ] ];
        }



    }
    return 0;
}