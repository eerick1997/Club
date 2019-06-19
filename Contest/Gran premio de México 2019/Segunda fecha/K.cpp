#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const lli MINFTY = -1000000;
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
    lli rows, cols, v;
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> rows >> cols;
    Matrix m( rows, vi(cols, 0) );
    vi k_r( rows, 0 );
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> v;
            m[i][j] = ( v == 0 ? 1 : MINFTY );
            if(j > 0)
                m[i][j] += m[i][j - 1];
        }
    }

    printMatrix(m);
    //2D kadane's algorithm
    lli area, maxArea = MINFTY, perimeter = MINFTY;
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0, a_y1 = 0, a_y2 = 0;
    for(int l = 0; l < cols; l++){
        for(int r = l; r < rows; r++){
            area = 0;
            for(int row = 0; row < rows; row++){
                //Max 1D range sum on columns of this row
                if(l > 0) {
                    area += m[row][r] - m[row][l - 1];
                } else {
                    area += m[row][r];
                }

                //1D Kadane's 
                if(area < 0){
                    area = 0;
                    a_y1 = row + 1;
                } else if(area > maxArea) {
                    x1 = l + 1;
                    x2 = r + 1;
                    y1 = a_y1 + 1;
                    y2 = row + 1;
                    maxArea = area;
                    perimeter = max( perimeter, (lli)( 2 * ( (x2 - x1 + 1) + (y2 - y1 + 1) ) ) );
                    cout << "(" << x1 << "," << y1 << ") (" << x2 << "," << y2 << ")" << endl; 
                    cout << "b "<< (x2 - x1 + 1) << " h " << (y2 - y1 + 1) << endl;
                    cout << "area " << maxArea << " perimeter " << perimeter << endl;
                }
            }
        }
    }
    
    
    cout << ( perimeter < 0 ? 0 : perimeter) << endl;
    return 0;
}