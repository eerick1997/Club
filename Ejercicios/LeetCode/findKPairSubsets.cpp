#include <bits/stdc++.h>

using namespace std;

map< int, int > numbers;
int n, k;

int getPairs( ){
    set< set<int> > subsets;
    int a, b;
    for( auto e : numbers ){
        if( e.second > 0 ){
            a = e.first;
            if( numbers[ k - a ] > 0 ){
                subsets.insert( {a, numbers[ k - a ] } );
                numbers[ k - a ]--;
            }
        }
    }
    return subsets.size();
}

int main(){
    cin >> n >> k;
    for( int i = 0, v; i < n; i++ ){
        cin >> v;
        numbers[ v ]++;
    }

    cout << getPairs() << endl;
    return 0;
}