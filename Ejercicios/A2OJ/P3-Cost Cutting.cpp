#include <iostream>

using namespace std;

int main(){

	int T = 0, A = 0, B = 0, C = 0;
	cin>>T;
	for(int i  = 0; i < T; i++){
		cin>>A>>B>>C;
		//A es el más grande luego B
		if(A > B && B > C){
			cout<<"Case "<<i+1<<": "<<B<<endl;
		//El más grande es C y luego A
		} else if(C > A && A > B){
			cout<<"Case "<<i+1<<": "<<A<<endl;
		//El más grande es B luego C
		} else if(B > C && C > A){
			cout<<"Case "<<i+1<<": "<<C<<endl;
		//A es el más grande luego C
		} else if(A > C && C > B){
			cout<<"Case "<<i+1<<": "<<C<<endl;
		//C es el más grande luego B
		} else if(C > B && B > A){
			cout<<"Case "<<i+1<<": "<<B<<endl;
		} else if(B > A && A > C){
			cout<<"Case "<<i+1<<": "<<A<<endl;
		}
	}
	return 0;
}

/**

Solución 2 
	int N;
	vector<int> num(3);
	cin>>N;
	for(int i = 1; i <= N; i++){
		cin>>num[0]>>num[1]>>num[2];
		sort(num.begin(), num.end());
		cout<"Case "<<i<<": "<<num[1]<<endl;
	}
**/