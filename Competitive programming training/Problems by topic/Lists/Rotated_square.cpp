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
    vector< string > rot_small( small );
    
}


int main() {
    int dim_big_square, dim_small_square;   
    vector< vector< char > > big_square;
    vector< vector< char > > small_square;
    string buffer;
    while( cin >> dim_big_square >> dim_small_square and dim_small_square and dim_small_square ) {
        big_square.resize( n, vector<char>( n ) );
        small_square.resize( m, vector< char >( m ) );
        small_square.resize( n );
        for( int i = 0; i < dim_big_square; i++ ) {
            cin >> buffer;
            big_square.push_back( buffer );
        }
    
        for( int i = 0; i < dim_small_square; i++) {
            cin >> buffer;
            small_square.push_back( buffer );
        }



    }
    return 0;
}