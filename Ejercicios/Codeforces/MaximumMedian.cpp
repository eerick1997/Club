#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli f( vector<lli> &numbers, lli begin, lli end, lli middle ){
    for( int i = 0; i < numbers.size(); i++ ){

    }

}

lli binarySearch( vector<lli> &numbers, lli k){
    lli begin = (numbers.size() / 2), end = numbers.size(), middle = 0;
    while( begin < end ){
        
        if( f( numbers, begin, end, middle ) ){
            
        } else {

        }
    } 
}

int main(){
    lli n, k;
    vector<lli> numbers:
    cin >> n >> k;
    numbers.resize( n, 0 );
    for( int i = 0; i < n; i++ )
        cin >> numbers[ i ];
    sort( numbers.begin(), numbers.end() );
    cout << binarySearch( numbers, k ) << endl;
    return 0;
}