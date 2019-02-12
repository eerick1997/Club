#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


struct WaveletTree
{
	lli lo, hi;
	WaveletTree *left, *right;
	vector<lli> mapLeft;

	WaveletTree(vector<lli>::iterator from, vector<lli>::iterator to, lli lo, lli hi){
		this->lo=lo;
		this->hi=hi;
		if(from >= to) 
			return;
		lli m = (lo + hi) >> 1;
		auto f = [m](lli x){
			return x <= m;
		};
		mapLeft.reserve(to - from + 1);
		mapLeft.push_back(0);
		

		for(auto it = from; it != to; ++it){
			auto leq = f(*it);
			mapLeft.push_back(mapLeft.back() + leq);
		}

		if(hi != lo){
		
			auto pivot = stable_partition(from, to, f);
			left = new WaveletTree(from, pivot, lo, m);
			right = new WaveletTree(pivot, to, m + 1, hi);
		}
	}

	lli kth(lli l, lli r, lli k){
		if(l > r) 
			return -1;
		if(lo == hi) 
			return lo;
		lli lb = mapLeft[l - 1], rb = mapLeft[r];
		lli inLeft = rb - lb;
		if(k <= inLeft) 
			return left->kth(lb + 1, rb, k);
			return right->kth(l - lb, r - rb, k - inLeft);
	}

	lli lessThanOrEqual(lli l, lli r, lli x){
		if(l > r || x < lo) 
			return 0;
		if(hi <= x) 
			return r - l + 1;
		lli lb = mapLeft[l - 1], rb = mapLeft[r];
		return left->lessThanOrEqual(lb + 1, rb, x) + right->lessThanOrEqual(l - lb, r - rb, x);
	}
};

int main(){
	lli n, q;
	cin >> n;
	vector<lli> num(n);
	for (lli i = 0; i < n; ++i){
		cin >> num[i];
	}
	WaveletTree w(num.begin(), num.end(),*min_element(num.begin(), num.end()),*max_element(num.begin(), num.end()));
    while(q--){
        lli i, j, k;
        cin >> i >> j >> k;
        cout << (w.lessThanOrEqual(i, j, k)) << endl;
    }
	return 0;
}