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
    lli n;
    bool flag;
    cin >> n;
    while(n--){
        string l1, l2;
        vector<comp> A;
        vector<comp> B;
        vector<comp> ans;
        flag = false;
        cin >> l1 >> l2;
        int size = max(l1.size(), l2.size());
        A.resize(l1.size());
        B.resize(l2.size());
        for(int i = 0; i < l1.size(); i++){
            A[i] = l1[i] - '0';
        }
        for(int i = 0; i < l2.size(); i++){
            B[i] = l2[i] - '0';
        }
            
        ans = convolution(A, B);
    
        for(int i = ans.size() - 1; i > 0; i--){
            int real = round(ans[i].real());
            if(real > 9){
                ans[i - 1].real( round(ans[i - 1].real() + real / 10) );
                ans[i].real( real % 10 );
            }
        }

        for(int i = 0; i < ans.size(); i++){

            if( round( ans[i].real() ) != 0 )
                flag = true;
            
            if( flag ){
                cout << abs(round( ans[i].real() ));
            }

        }

        if(!flag)
            cout << 0;

        cout << endl;
    }
    return 0;
}