#include<iostream>
#include<iomanip>

using namespace std;
int main(){
	int a = 0;
	double n = 1;
	cin>>a;
	for(int i=1; i<=a; i++)
		n *= 2;
	cout<<setprecision(80)<<n;

	return 0;
}