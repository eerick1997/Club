#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector<float> v(100, 0);

	int duration = 0, records = 0, month = 0;
	float down_payment = 0.0, amount = 0.0, rate = 0.0, initial = 0.0, monthly_payment = 0.0;

	while(cin>>duration>>down_payment>>amount>>records && duration > 0){

		while(records--){
			cin>>month>>rate;
			for(int i = month; i < v.size(); i++){
				v[i] = rate;
			}
		}

		initial = (amount + down_payment)*(1-v[0]);
		monthly_payment = amount/duration;

		int pos_vector = 0;
		while((initial < amount)){
			amount -= monthly_payment;
			initial*=(1-v[++pos_vector]);
		}

		cout<<pos_vector<<" month";
		if(pos_vector != 1)cout<<"s";
		cout<<endl;
	}
	
	return 0;
}