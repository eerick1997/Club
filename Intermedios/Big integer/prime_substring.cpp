#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<bool> buildSieve(lli n){
    lli root = sqrt(n);
    vector<bool> sieve(n + 2, true);
    for(lli i = 4; i <= n; i+=2){
        sieve[i] = false;
    }

    for(lli i = 3; i <= root; i++){
        if(sieve[i])
            for(lli j = i*i; j <= n; j += i)
                if(sieve[j])
                    sieve[j] = false;
    }

    return sieve;
}

int main(){
    vector<bool> sieve = buildSieve(100000);
    string s;
    while(1){
        lli ans = -1;
        cin >> s;
        if(s == "0")
            break;
        for(lli i = 0; i < s.size(); i++){
            lli number = 0;
            for(lli j = 0; j < s.size(); j++){
                string substring = s.substr(i, j);
                if(substring == "" || substring == "\t")
                    continue;

                if(substring.size() > 6)
                    continue;

                number = stol(substring);

                if(number > 100000)
                    continue;
                
                if(sieve[number]){
                    ans = max(ans, number);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}