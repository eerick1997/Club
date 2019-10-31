#include <bits/stdc++.h>

using namespace std;
int DP[ 2000 ][ 2 ], n;
vector< int > sequence;

int LIS( int index, int lastNumber ){
    if( index == n )
        return 0;

    if( sequence[ index ] > lastNumber ){
        
    }
        
}


int main(){
    cin >> n;
    sequence.resize( n );

    for( int i = 0; i < n; i++ )
        cin >> sequence[ i ];
    return 0;
}