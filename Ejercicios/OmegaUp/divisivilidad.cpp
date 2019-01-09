#include <iostream>
#include <math.h>

using namespace std;

int N, P, a[18+5];

int main(){	
	cin>>N>>P;
	long long pot = 1;
	for(int i = 0; i < N; i++){
		a[i] = pot%P;
		pot *= 10;
	}
	for(int i = N-1; i>0; i--)
		cout<<a[i]<<" ";
	cout<<a[0]<<"";
	return 0;
}