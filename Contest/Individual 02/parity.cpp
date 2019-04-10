#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){

    lli b, k, ans = 0, p;
    vector<lli> a;
    cin >> b >> k;
    a.resize(k);
    for(int i = 0; i < k; i++)
        cin >> a[i];
    

    p = 1;
    for(int i = k - 1; i >= 0; i--){
        ans = (ans + a[i] * p) % 2;
        p = (lli)( (lli)(p * b) % 2 );
    }

    cout << ( (!ans)? "even" : "odd" ) << endl;
}