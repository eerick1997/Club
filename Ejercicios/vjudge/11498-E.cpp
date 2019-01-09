#include<iostream>

using namespace std;

int main(){
	
	int x, y, K = 1, N, M;

	while(cin>>K && K != 0){
		cin>>N>>M;
		for(int i  = 0; i <  K; i++){
			cin>>x>>y;
			if(x > N && y > M) cout<<"NE"<<endl;
			else if(x > N && y < M) cout<<"SE"<<endl;
			else if(x < N && y > M) cout<<"NO"<<endl;
			else if(x < N && y < M) cout<<"SO"<<endl;
			else cout<<"divisa"<<endl; 
		}
	}

	return 0;
}