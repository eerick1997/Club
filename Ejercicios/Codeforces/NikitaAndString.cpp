#include <bits/stdc++.h>

using namespace std;
vector< vector< int > > DP;
string s;
int n;

int solution( int index, int group ){
    int A = 0, B = 0, C = 0;
    if( index == n )
        return 0;    
    
    if( DP[ index ][ group ] != -1 )
        return DP[ index ][ group ];

    if( group == 0 ){
        if( s[ index ] == 'a' )
            B = solution( index + 1, group ) + 1;
        else {
            //Change group or ignore the next character
            A = solution( index, 1 );
            C = solution( index + 1, group );
        }
        return DP[ index ][ group ] = max( {A, B, C} );
    } else if( group == 1 ){
        if( s[ index ] == 'b')
            B = solution( index + 1, group ) + 1;
        else {
            A = solution( index, 2 );
            C = solution( index + 1, group );
        }
        return DP[ index ][ group ] = max( { A, B, C } );
    } else {
        if( s[ index ] == 'a' )
            A = solution( index + 1, group ) + 1;
        else 
            B = solution( index + 1, group );
        return DP[ index ][ group ] = max(A, B);
    }

}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    cin >> s;
    n = s.size();
    DP.assign( n, vector< int > ( 4, -1 ) );
    cout << solution( 0, 0 ) << endl; 
    return 0;
}