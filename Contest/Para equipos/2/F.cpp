#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

double operation(lli s_i, lli A, lli S){
    return ( (s_i*A) / (S) );
}

int main(){
    vector<lli> s;
    lli n, A, B, S = 0, s_0 = 0;
    cin >> n >> A >> B;
    s.resize(n);

    for(lli i = 0; i < n; i++){
        cin >> s[i];
        S += s[i];
    }

    s_0 = s[0];

    sort(s.begin() + 1, s.end());

    lli ans = 0;
    for(lli i = (n - 1); i >= 1; i--){
        if( operation(s_0, A, S) >= B)
            break;
        S -= s[i];
        ans++;
    }

    cout << ans << endl;
    return 0;
}