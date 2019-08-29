#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

bool f( vector< int > &N, int begin, int end, int middle ) {

    for( int i = begin + 1; end)
}

int main(){
    int n;
    cin >> n;
    lli begin, end, middle;
    vector< int > N( n );
    for( int i = 0; i < n; i++ )
        cin >> N[ i ];
    
    begin = n / 2;
    end = n;
    while( begin <= end ){
        middle = ( begin + end ) / 2;
        if( f( N, begin, end, middle ) ){

        } else {
            
        }
    }
}