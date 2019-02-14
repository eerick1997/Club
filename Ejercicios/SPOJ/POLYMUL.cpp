#include <bits/stdc++.h>

using namespace std;
using comp = complex<double>;
using lli = long long int;
const double PI = acos(-1.0);

int nearestPowerOfTwo(int n){
	int ans = 1;
	while(ans < n) ans <<= 1;
	return ans;
}

void fft(vector<comp> & X, int inv){
	int n = X.size();
	for(int i = 1, j = 0; i < n - 1; ++i){
		for(int k = n >> 1; (j ^= k) < k; k >>= 1);
		if(i < j) swap(X[i], X[j]);
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
	A.resize(size), B.resize(size);
	fft(A, 1), fft(B, 1);
	for(int i = 0; i < size; i++)
		A[i] *= B[i];
	fft(A, -1);
	A.resize(sz);
	return A;
}

int main(){
    vector<comp> A;
    vector<comp> B;
    vector<comp> ans;
    lli T;
    lli n;
    cin >> T;
    while(T--){
        
        comp v;
        cin >> n;
        for(lli i = 0; i <= n; i++){
            cin >> v;
            A.push_back(v);
        }
        for(lli i = 0; i <= n; i++){
            cin >> v;
            B.push_back(v);
        }
        ans = convolution(A, B);
        for(lli i = 0; i < ans.size(); i++)
            cout << (lli)round(ans[i].real()) << " ";
        cout << endl;
        A.clear();
        B.clear();
        ans.clear();
    }

    return 0;
}