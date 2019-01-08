/** Worms **/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	//n = number of piles, m = number of juicy worms
	int n, m, last = 0;
	//a_i = number of worms in the a_ith pile
	vector<int> a;
	//a.push_back(0);

	//q_i = labels of  the juicy worms
	vector<int> q; 

	//Getting number of piles
	cin>>n;
	while(n--){
		//Data
		int d = 0;
		cin>>d;
		last += d;
		a.push_back(last);	
	}

	for(int i = 0; i < a.size(); i++){
		cout<<"|"<<a[i]<<"|";
	}
	cout<<endl;

	//Getting number of juicy worms
	cin>>m;
	while(m--){
		//Data
		int d = 0;
		cin>>d;
		q.push_back(d);
	}

	for(int  i = 0; i < q.size(); i++){

		int val = q[i];
		int begin = 0, end = q.size()-1, middle, res = -1;
		cout<<"Search "<<val<<endl;
		//Binary search
		while(begin <= end){
			middle = (begin + end) / 2;


			if(val > a[middle]) {
				begin = middle + 1;
			} else {
				end = middle - 1;
				res = middle;	
			}

		}

		cout<<res<<endl;
	}

	return 0;
}