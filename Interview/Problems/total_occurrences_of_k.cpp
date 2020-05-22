#include <bits/stdc++.h>

using namespace std;

int main() {
    int32_t k, n, buffer, left, right;
    vector< int32_t > arr;
    cin >> n >> k;
    arr.resize( n );
    for( int32_t i = 0; i < n; i++ )
        cin >> arr[ i ];
    
    //Binary search
    int32_t begin, end, middle;
    begin = 0, end = n - 1;
    while( begin <= end ) {
        middle = begin + ( end - begin ) / 2;
        if( arr[ middle ] <= k )
            begin = middle + 1, right = begin;
        else 
            end = middle - 1;
    }
    begin = 0, end = n - 1;
    while( begin <= end ) {
         middle = begin + ( end - begin ) / 2;
        if( arr[ middle ] <= (k - 1) )
            begin = middle + 1;
        else 
            end = middle - 1;
    }
    left = begin;
    cout << ( right - left ) << endl;
    return 0;
}