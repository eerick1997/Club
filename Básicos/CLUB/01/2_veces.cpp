#include <iostream>

using namespace std;

int main(){
	string str;
	while(getline(cin, str)){
		for(int i = 0; i < str.size(); i++){
			char UpperChar = toupper(str[i]);
			cout<<UpperChar;
		}
		cout<<'\n';
		for(int i = 0; i < str.size(); i++){
			char LowerChar = tolower(str[i]);
			cout<<LowerChar;
		}
		cout<<'\n';

	}
	return 0;
}