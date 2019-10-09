#include <bits/stdc++.h>

using namespace std;
vector< pair< int, int > > coders;
int N;

double f( double m ){
    double MAX = INT32_MIN, MIN = INT32_MAX;
    for( int i = 0; i < N; i++ ){
        MIN = min( coders[ i ].first * m + coders[ i ].second, MIN );
        MAX = max( coders[ i ].first * m + coders[ i ].second, MAX );
    }
    return ( MAX - MIN );
}

int main(){
    int K, D, S;
    cin >> N >> K;
    double ans = 0;
    coders.assign( N, { 0, 0 } );
    for( int i = 0; i < N; i++ )
        cin >> coders[ i ].first >> coders[ i ].second;
    
    double left = 0, right = K, m_1, m_2, f_1, f_2;
    for( int i = 0; i < 30; i++ ){

        m_1 = left + ( ( right - left ) / 3 );
        m_2 = right - ( ( right - left ) / 3 );
        f_1 = f( m_1 );
        f_2 = f( m_2 );
        
        if( f_1 < f_2 )
            left = m_1;
        else 
            right = m_2;

    }
    
    cout << fixed << setprecision( 6 ) << ans << endl;
    return 0;
}