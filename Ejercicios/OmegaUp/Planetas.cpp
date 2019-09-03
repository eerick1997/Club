#include <bits/stdc++.h>

using namespace std;
vector< double > planets;
int n;
//\sum^{ n }_{ 0 }{ \frac{ 1 }{ X_{i} - M } }
double SumOfForces( double middle ){
    double sum = 0.0;
    for( int i = 0; i < n; i++ ){
        sum += 1 / ( planets[ i ] - middle );
    }
    return sum;
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    cin >> n;
    planets.resize( n );
    for( int i = 0; i < n; i++)
        cin >> planets[ i ];
    sort( planets.begin(), planets.end() );
    cout << n - 1 << endl; 
    for( int i = 0; i < n - 1; i++ ){
        double begin = planets[ i ];
        double end = planets[ i + 1 ];
        double middle;
        for( int i = 0; i < 25; i++ ){
            middle = ( begin + end ) / 2;
            if( SumOfForces( middle ) < 0 ){
                begin = middle;
            } else {
                end = middle;
            }
        }
        cout << fixed;
        cout << setprecision( 3 );
        cout << middle << " "; 
    }
    cout << endl;
    return 0;
}