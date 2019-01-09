#include <iostream>
#include <cmath>

using namespace std;

typedef long long int lli;

long gcd(long a, long b){
	if(b == 0)
		return a;
	return gcd(a, a % b);
}

long lcm(long a, long b){
	if(b == 0)
		return a;
	return 0;
}

int main(){
	
	long GCD = gcd(9, 24);
	long LCM = ((abs(9) * abs(24))/GCD);
	cout<<GCD<<endl;
	cout<<LCM<<endl;

	return 0;
}
