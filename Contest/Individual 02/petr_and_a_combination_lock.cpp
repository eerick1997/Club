#include <bits/stdc++.h>

using namespace std;

int mod(int n){
    int m = 360;
    return ( (n < 0) ? m - ( abs(n) % m ) : n % m );
}

int ans(vector<int> &a, int i, int v){

    v = mod(v);

    if(i == a.size()){
        return v;
    }
    
    return min( ans(a, i + 1, v - a[i]), ans(a, i + 1,v + a[i]));

}

int main(){
    vector<int> a;
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    
    cout << ( ( ans(a, 0, 0) == 0) ? "YES" : "NO") << endl; 
}