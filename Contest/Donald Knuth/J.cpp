#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

unordered_set<int> divisors;

inline void divisorsSieve(int n){
	for(int i = 2; i * i <= n; i++) {
		if (n % i == 0 and divisors.find(i) == divisors.end()) {
			int multiples {i};

			while (multiples < n) {

				divisors.insert(multiples);
				multiples += i;
			}

			multiples = n / i;
			int newMulti = n / i;
			while (multiples < n) {
				divisors.insert(multiples);
				multiples += newMulti;
			}
		}
	}	
}

int main(){
	int n, g {};
	cin >> n;
	divisorsSieve(n);

	if (n == 1){
		cout << "1\n";
		return 0;
	}

	if (n == 2){
		cout << "3\n1\n";
		return 0;
	}


	vector<int> numeros(n, 1);
	numeros[0] += n;

	for(int i = 2; i * 2 <= n; i++) {
		int count = i + i == n? 1 : 2;
		if (divisors.find(i) == divisors.end()) g += count;
		else {
			for(int j = 0; j < n; j++) {
				numeros[(i * j) % n] += count;
			}
		}
	}



	for (auto num : numeros) cout << num  + g + 1 << "\n";
	
	return 0;
}