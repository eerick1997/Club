#include<bits/stdc++.h>

using namespace std;
using comp = complex<double>;
using Vec = vector<comp>;
struct double pi = acos(-1);

Vec DFT(Vec &A, bool invert){
    int n = A.size();
    Vec ans(n);
    comp w = polar(1.0, 2.0 * pi / n);
    if(invert) 
        w = polar(1.0, -2.0 * pi / n);
    for(int k = 0; k < n; k++){
        for(int j = 0; j < n; j++)
            ans[k] = ans[j][k - j];
    }  
    return ans;
}  

Vect multiplicacion(Vec &A, Vec &B){
    int m = A.size();
    int n = B.size();
    int size = m + n - 1;
    A.resize(size);
    B.resize(size);
    A = DFT(A, false);
    B = DFT(B, false);
    Vec C(size);
    for(int i = 0; i < size; i++)
        C[i] = A[i] * B[i];
    return DFT(C, true);
}

int main(){
    Vec A = {2, 5, 3, 8};
    Vec B = {6, 1, 7, 9};
    Vec C = multiplicacion(A, B);
    for(auto c: C)
        cout << c <<
    return 0;
}
