#include <bits/stdc++.h>

using namespace std;
int DP[4005];
int num[3];
int n;

int cutRibbon( int ribbonLeft, int cuts ){
    
    if( ribbonLeft == 0 )
        return cuts;

    if( ribbonLeft < 0 )
        return INT_MIN;

    if( DP[ ribbonLeft ] != -1 )
        return DP[ ribbonLeft ];

    int A = cutRibbon( ribbonLeft - num[0], cuts + 1 );
    int B = cutRibbon( ribbonLeft - num[1], cuts + 1 );
    int C = cutRibbon( ribbonLeft - num[2], cuts + 1 );

    return DP[ ribbonLeft ] = max( { A, B, C } );
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    memset( DP, -1, sizeof( DP ) );
    cin >> n >> num[0] >> num[1] >> num[2];
    sort(num, num + 3);
    cout << cutRibbon( n, 0 ) << endl;

    return 0;
}