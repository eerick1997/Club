#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

map<lli, lli> bucket;
map<lli, lli> h_bucket;

int main(){

    lli N = 0;
    lli b = 0;  
    cin >> N;
    for(int i = 0; i < N; i++){
        lli t, s, l;
        cin >> t >> s;
        if(t == 2)
            b++;
        while(s--){
            cin >> l;
            if(t == 1){
                bucket[l]++;
            } else if(t == 2){
                bucket[l]--;
                h_bucket[l]++;
            }
        }
    }
    lli ans = 0;
    if(N != b){
        for(map<lli, lli>::iterator it = bucket.begin(); it != bucket.end(); it++){
            if(it -> second == (N - b) || it -> second >= N)
                ans++;
        }
    }
    if(b == N) ans = (1e18 - h_bucket.size());
    printf("%lld\n", ans );
    return 0;
}