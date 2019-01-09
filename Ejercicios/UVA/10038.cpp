#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(){

	vector<int> v;
	bool isJolly = true;
	int n = 0, actual = 0, next  = 0;

	//We read n if n > 0
	while(cin>>n && n > 0){

		isJolly = true;
		v.clear();

		//We read the first number
		cin>>actual;
		//Case when n == 1 (we read just a number)
		if(n == 1){
			//Ever it is Jolly
			v.push_back(1);

		} 
		//Case when n == 2 (we read two numbers [a line])
		else if(n == 2) {
			//We read the second number
			cin>>next;
			//We store |actual - next|
			v.push_back(abs(actual - next));
			//We need to know if the value stored is less than (n-1)
			//this condition it's necessary to know if it's a Jolly jumper
			if(v[0] > (n-1))
				isJolly = false;

		} 
		//We read n - 1 numbers (We read 1 number before)
		else {
			//We read the second number
			cin>>next;
			//We store |actual  - next| value
			v.push_back(abs(actual-next));
			//We read n - 2 numbers
			for(int i = 2; i < n; i++){
				//The actual value now it's the next
				actual = next;
				//So next need to be a new value
				cin>>next;
				//We sote |actual - next| value
				v.push_back(abs(actual - next));
			}

			//We order the vector
			sort(v.begin(), v.end());

			//We add a number at the end of our vector
			v.push_back(0);

			//We need to know if each element of our vector has a sequence
			for(int  i = 0; i < v.size()-2; i++){

				//We make an operation to know if each element it's an element of this sequence
				int dif = abs(v[i] - v[i+1]);

				//If it's not an element, numbers aren't a Jolly jumper
				if(dif != 1){
					isJolly = false;
					break;
				}

			}

			//Finally
			//We need to know if the value stored is less than (n-1)
			//this condition it's necessary to know if it's a Jolly jumper
			if(v[v.size()-2] > (n-1))
				isJolly = false;
		}

		//We just print if it's a Jully jumper
		if(isJolly){
			cout<<"Jolly"<<endl;
		} else {
			cout<<"Not jolly"<<endl;
		}

	}
	return 0;	
}