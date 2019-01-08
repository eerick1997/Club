#include <bits/stdc++.h>

using namespace std;

int main(){

    string n1, n2;
    while(1){
        int carry = 0;

        cin >> n1 >> n2;
        if(n1 == "0" && n2 == "0") break;

        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());

        if(n1.size() < n2.size()){
            while(n1.size() != n2.size()) 
                n1 += '0';
        } else {
            while(n1.size() != n2.size()) 
                n2 += '0';
        }

        int a_carry = 0;
        for(int i = 0; i < n1.size(); i++){
            int suma = (n1[i] - '0') + (n2[i] - '0') + a_carry;
            if(suma > 9){
                a_carry = 1;
                carry++;
            } else a_carry = 0;
        }

        if(carry == 0)
            cout << "No carry operation." << endl;
        else if(carry == 1)
            cout << "1 carry operation." << endl;
        else
            cout << carry << " carry operations." << endl;
    }
    return 0;
}