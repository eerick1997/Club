#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli solution(vector<lli> &a, lli k){
    lli ans = 0;
    for(int i = 0; i < a.size(); i++)
        ans += a[i];

    return ( !(k >= ans) ) ? k : ceil(ans / k);
}

int main(){
    lli n, k;
    vector<lli> a;
    cin >> n >> k;
    a.resize(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solution(a, k) << endl;
}