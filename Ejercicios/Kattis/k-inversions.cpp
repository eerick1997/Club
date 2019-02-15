#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
using comp = complex<double>;
const double PI = acos(-1.0);

int nearestPowerOfTwo(int n){
    int ans = 1;
    while(ans < n) 
        ans <<= 1;
    return ans;
}

void FFT(vector<comp> &X, int inv){
    int n = X.size();
    for(int i = 1, j = 0; i < n - 1; ++i){
        for(int k = n >> 1; (j ^= k) < k; k >>= 1);
        if(i < j)
            swap(X[i], X[j]);
    }
    for(int k = 1; k < n; k <<= 1){
        comp wk = polar(1.0, PI / k * inv);
        for(int i = 0; i < n; i += k << 1){
            comp w(1);
            for(int j = 0; j < k; ++j, w = w * wk){
                comp t = X[i + j + k] * w;
                X[i + j + k] = X[i + j] - t;
                X[i + j] += t;
            }
        }
    }
    if(inv == -1)
        for(int i = 0; i < n; ++i)
            X[i] /= n;
}

vector<comp> convolution(vector<comp> A, vector<comp> B){
    int sz = A.size() + B.size() - 1;
    int size = nearestPowerOfTwo(sz);
    A.resize(size);
    B.resize(size);
    FFT(A, 1);
    FFT(B, 1);
    for(int i = 0; i < size; i++)
        A[i] *= B[i];
    FFT(A, -1);
    A.resize(sz);
    return A;
}

int main(){
    vector<comp> A;
    vector<comp> B;
    comp one (1,0);
    string str;
    cin >> str;
    A.resize(str.size(), 0);
    B.resize(str.size(), 0);
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'A')
           A[i] += one;
        else
            B[i] += one;
    }
    reverse(B.begin(), B.end());
    vector<comp> ans = convolution(A, B);
    for(int i = ans.size() / 2 + 1; i < ans.size(); i++)
        cout << abs(round(ans[i].real())) << endl;
    if(ans.size() == 1)
        cout << 0 << endl;
}