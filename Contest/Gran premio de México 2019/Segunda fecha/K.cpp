#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const lli MINFTY = -1000000;
typedef vector< vector <lli> > Matrix;
typedef vector< lli > vi;

void printMatrix(Matrix &m){
    cout << endl;
    for(int i = 1; i < m.size(); i++){
        for(int j = 1; j < m[i].size(); j++){
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
    Matrix m( rows + 1, vi(cols + 1, 0) );
    vi k_r( rows, 0 );
    for(lli i = 1; i <= rows; i++){
        for(lli j = 1; j <= cols; j++){
            cin >> v;
            m[i][j] = (v == 0) ? 1 : MINFTY;
        }
    }

    printMatrix(m);
    //Acummulative sum 2D
    for(int i = 1; i <= rows; i++){
        //Making the sum by rows
        for(int j = 1; j <= cols; j++)
            m[i][j] += m[i][j - 1];

        //Making the sum by cols
        for(int j = 1; j <= cols; j++)
            m[i][j] += m[i - 1][j];
    }

    printMatrix(m);
    //2D kadane's algorithm
    for(int l = 1, sum = 0; l <= cols; l++){
        for(int r = l, sum = 0; r <= cols; r++){
            area = 0;
            for(int row = 1; row < r; row++){
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