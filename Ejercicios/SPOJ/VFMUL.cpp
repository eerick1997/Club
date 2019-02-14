#include <bits/stdc++.h>

using namespace std;
using comp = complex<double>;
using lli = long long int;
const double PI = acos(-1.0);

lli p = 7340033;
lli root = 5;
lli root_pw = 1 << 20;

lli nearestPowerOfTwo(lli n){
    lli ans = 1;
    while(ans < n)
        ans <<= 1;
    return ans;
}

lli inverse(lli a, lli n){
	lli r0 = a, r1 = n, ri, s0 = 1, s1 = 0, si;
	while(r1){
		si = s0 - s1 * (r0 / r1), s0 = s1, s1 = si;
		ri = r0 % r1, r0 = r1, r1 = ri;
	}
	if(s0 < 0) s0 += n;
	return s0;
}

lli root_1 = inverse(root, p);

void NTT(vector<lli> &X, lli inv){
	lli n = X.size();
	for(lli i = 1, j = 0; i < n - 1; ++i){
		for(lli k = n >> 1; (j ^= k) < k; k >>= 1);
		if(i < j) swap(X[i], X[j]);
	}
	for(lli k = 1; k < n; k <<= 1){
		lli wk = (inv == -1) ? root_1 : root;
		for(lli i = k << 1; i < root_pw; i <<= 1)
			wk = (lli)wk * wk % p;
		for(lli i = 0; i < n; i += k << 1){
			for(lli j = 0, w = 1; j < k; ++j, w = (lli)w * wk % p){
				lli u = X[i + j], v = (lli)X[i + j + k] * w % p;
				X[i + j] = u + v < p ? u + v : u + v - p;
				X[i + j + k] = u - v < 0 ? u - v + p : u - v;
			}
		}
	}
	if(inv == -1){
		lli nrev = inverse(n, p);
		for(lli i = 0; i < n; ++i)
			X[i] = (lli)X[i] * nrev % p;
	}
}

vector<lli> convolution(vector<lli> A, vector<lli> B){
    lli sz = A.size() + B.size() - 1;
    lli size = nearestPowerOfTwo(sz);
    A.resize(size);
    B.resize(size);
    NTT(A, 1);
    NTT(B, 1);
    for(lli i = 0; i < size; i++)
        A[i] = (lli)A[i] * B[i] % p;
    NTT(A, -1);
    A.resize(sz);
    return A;
}

int main(){
    lli T;
    lli n;
    cin >> T;
    while(T--){
        vector<lli> A;
        vector<lli> B;
        vector<lli> ans;
        cin >> n;
        for(lli i = 0, v = 0; i <= n; i++){
            cin >> v;
            A.push_back(v);
        }

        for(lli i = 0, v = 0; i <= n; i++){
            cin >> v;
            B.push_back(v);
        }
        ans = convolution(A, B);
        for(lli i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}