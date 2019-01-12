#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
vector< lli > Xi;

lli proof(lli M){
    lli current = 0;
    lli count = 1;
    for(int i = 1; i < Xi.size(); i++){
        lli difference = Xi[i] - Xi[current];
        if(difference >= M){
            current = i;
            count++;
        }
    }
    return count;
}

int main(){
    lli T;
    cin >> T;
    while(T--){
        lli N, C;
        Xi.clear();
        cin >> N >> C;
        for(lli i = 0, V = 0; i < N; i++){
            cin >> V;
            Xi.push_back(V);
        }
        sort(Xi.begin(), Xi.end());

        lli begin = 1;
        lli end = 1 << 30;
        lli ans = 0;
        while(begin <= end){
            lli middle = (begin + end) >> 1;
            if(proof(middle) < C){
                end = middle - 1;
            } else {
                begin = middle + 1;
                ans = middle;
            }
        }
        cout << ans << endl;
    }
    return 0;
}