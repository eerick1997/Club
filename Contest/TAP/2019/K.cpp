#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair< lli, lli > plli;

lli getIntersection( plli &eD, plli &eJ ){
    return abs( abs( abs( eD.first - eJ.first ) - abs( eD.second - eJ.second ) ) );
}


int main(){
    lli N, ans = 0, begin = 0, end = 0;
    char c;

    vector< plli > D, J;    
    cin >> N;
    for( int i = 0; i < N; i++ ){
        cin >> c >> begin >> end;
        if( c == 'D' )
            D.push_back( {begin, end} );
        else 
            J.push_back( {begin, end} );
    }

    sort( D.begin(), D.end() );
    sort( J.begin(), J.end() );

    lli ptrD = 0, ptrJ = 0;
    plli eD, eJ;
    cout << endl;
    while( ptrD < D.size() && ptrJ < J.size() ){
        eD = D[ ptrD ];
        eJ = J[ ptrJ ];

        if( eD.first <= eJ.second && eD.second >= eJ.first){
            cout << eD.first << " | " << eD.second << endl; 
            cout << eJ.first << " | " << eJ.second << endl; 
            ans = max( ans, getIntersection( eD, eJ ));
            ptrJ++, ptrD++;
        } else if( eD.first > eJ.second ){
            ptrD++;
        } else
            ptrJ++;

    }

    cout << ans << endl;
    return 0;
}