#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli exp(lli b, lli e, lli p){
    b %= p;
    lli ans = 1;
    while (e > 0){
        //si es par
        if( e & 1 )
            ans = ans * b % p ;
        b = b * b % p;
        e >>= 1;
    }
    return ans;
}


void is_generator(lli p){
    set<lli> a;
    for(int b = 2; b < p; b++){
        cout << "-> " << b << endl;
        vector<lli> a;
        for(int e = 0; e <= p; e++){
            a.insert( exp(b, e, p) );
            //sort(a.begin(), a.end());
            //cout << exp(b, e, p) << " ";
            //cout << ( (lli)pow(b, e) % p) << " ";
            //cout << b << " " << e << " " << p << endl;
        }
        //sort(a.begin(), a.end());
        for(auto el : a)
            c
        for(set<lli>::iterator it; it != a.end(); it++)
            cout << it[] << " ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    lli p;
    cin >> p;
    is_generator(p);
    return 0;
}