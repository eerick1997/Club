#include <bits/stdc++.h>

using namespace std;
vector< int > A;
double f( double m ){
    double m1, m2;

    return 0.0;
}

int main(){
    int n;
    cin >> n;
    A.assign( n, 0 );
    for(int i = 0; i < n; i++)
        cin >> A[ i ];
        
    double begin = 0, end = 1e30;
    double m_1 = 0, m_2 = 0;
    for( int i = 0; i < 30; i++ ){
        begin = begin + ( (end - begin) / 3 );
        end = end - ( (end - begin) / 3 );
        m_1 = f( begin ), m_2 = f( end );
        if( m_1 < m_2 ){
            begin = m_1;
        } else {
            end = m_2;
        }
    }
    return 0;
}