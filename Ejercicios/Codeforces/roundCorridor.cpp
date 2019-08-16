#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef long double lld;

int main(){
    lli n, m, q, c_1, c_2, e_1, e_2;
    lli n_walls, c_1_sections, c_2_sections;
    cin >> n >> m >> q;
    n_walls = __gcd( n, m );
    c_1_sections = n / n_walls;
    c_2_sections = m / n_walls;
    while( q-- ){
        cin >> c_1 >> e_1 >> c_2 >> e_2;
        if( n_walls == 1 ){
            cout << "YES" << endl;
            continue;
        }
        lld A = (lld)( (lld)e_1 / ( ( c_1 == 1 ) ? c_1_sections : c_2_sections ) );
        lld B = (lld)( (lld)e_2 / ( ( c_2 == 1 ) ? c_1_sections : c_2_sections ) );
        if( ceil(A) == ceil(B) )
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}