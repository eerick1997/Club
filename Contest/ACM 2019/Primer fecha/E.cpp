#include <bits/stdc++.h>

using namespace std;

int main(){
	string data {};
	cin >> data;

	long long ones {};
	for (auto symbol : data) {
		if (symbol == '1') ones++;
	}

	//	cout<<ones<<endl;
	long long result = ones;
	ones--;

	result += ((ones * (ones + 1)) / 2);

	cout << result << endl; 

	return 0;
}