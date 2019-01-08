#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;


int main(){

    lli N, M;
    vector<lli> Tk;
    cin >> N >> M;
    lli end = -1;
    for(lli i = 0; i < N; i++){
        lli v;
        cin >> v;
        Tk.push_back(v);
        end = max(end, (v * M) );
    }

    lli begin = 1;
    lli ans = 0;
    while(begin < end){
        lli middle = (begin + end) >> 1;
        lli total = 0;

        for(lli i = 0; i < N; i++){
            total += (middle / Tk[i]);
        }   

        if(total < M){
            begin = middle + 1;
        } else {
            ans = middle;
            end = middle;
        }
    }

    cout << ans << endl;
    return 0;
}
