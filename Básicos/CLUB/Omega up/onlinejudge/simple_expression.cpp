#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int ans = 0;
	vector<int> num(3);
	cin>>num[0]>>num[1]>>num[2];
	do{
		ans = min(ans, num[0] * num[1] * num[2]);
		ans = min(ans, num[0] * num[1] + num[2]);
		ans = min(ans, num[0] * num[1] - num[2]);
		ans = min(ans, num[0] + num[1] + num[2]);
		ans = min(ans, num[0] + num[1] - num[2]);
		ans = min(ans, num[0] + num[1] * num[2]);
		ans = min(ans, num[0] - num[1] - num[2]);
		ans = min(ans, num[0] - num[1] + num[2]);
		ans = min(ans, num[0] - num[1] * num[2]);
	} while(next_permutation(num.begin(),num.end()));//Permutaciones
	cout<<ans;
	return 0;
}