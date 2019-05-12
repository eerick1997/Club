#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef vector< vector <lli> > Matrix;
typedef vector< lli > vi;
lli ans = -1;
lli p;

inline lli suma(lli x1, lli y1, lli x2, lli y2, Matrix &m){
    return ( m[x2][y2] - (m[x2][y1 - 1] + m[x1 - 1][y2]) + m[x1 - 1][y1 - 1]);
}

inline lli valido(lli x1, lli y1, lli x2, lli y2){
    return abs( (x2 - x1) * (y2 - y1) );
}

inline lli perimetro(lli x1, lli y1, lli x2, lli y2){
    return 2 * ( abs(x2 - x1) + abs(y2 - y1) + 1 );
}


int main(){
    lli r, c, v;
    
    cin.tie(0);
    cin >> r >> c;
    Matrix matrix( r + 1, vi(c + 1, 0) );

    for(lli i = 1; i <= r; i++){
        for(lli j = 1; j <= c; j++){
            cin >> v; 
            matrix[i][j] = (v == 0) ? 1 : 0;
        }
    }

    for(lli j = 1; j <= c; j++){
        for(lli i = 2; i <= r; i++){
            matrix[i][j] += matrix[i- 1][j];
        }
    }

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            for(int k = i; k <= r; k++){
                for(int l = j; l <= c; l++){
                    lli area = suma(i, j, k, l, matrix);
                    if(valido(i, j, k, l) == area)
                        ans = max(ans, (perimetro(i, j, k, l)));
                }
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}