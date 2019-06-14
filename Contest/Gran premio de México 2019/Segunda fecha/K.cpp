#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
const lli MINF = -1 * (10e10);
typedef vector< vector <lli> > Matrix;
typedef vector< lli > vi;

void printMatrix(Matrix &m){
    cout << endl;
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[i].size(); j++){
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(){
    lli rows, cols, v, area = 0, perimeter = -1;
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> rows >> cols;
    Matrix m( rows, vi(cols, 0) );
    vi k_r( rows, 0 );
    for(lli i = 0; i < rows; i++){
        for(lli j = 0; j < cols; j++){
            cin >> v;
            m[i][j] = (v == 0) ? 1 : MINF;
        }
    }

    //2D kadane's algorithm
    for(int l = 0, sum = 0; l < cols; l++){
        for(int r = l, sum = 0; r < cols; r++){
            area = 0;
            for(int row = 0; row < r; row++){
                if(l > 0)
                    area += m[row][r] - m[row][l - 1];
                else 
                    area += m[row][r];
                if(area < 0)
                    area = 0;
                if(area != 0)
                    perimeter = max(perimeter, ( 2 * ( abs( r - l ) + abs( row -  cols ) + 1 ) ) );
            }
        }
    }

    cout << perimeter << endl;

    return 0;
}