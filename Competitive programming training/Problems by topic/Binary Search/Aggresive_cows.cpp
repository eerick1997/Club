#include <bits/stdc++.h>

using namespace std;
using lli = long long int;
vector<lli> stall;
int test_cases, n_stalls, n_cows;

lli check(lli min_distance) {
    lli cows = 1;
    lli last = 0;
    for(int i = 1; i < n_stalls; i++)
        if((stall[i] - stall[last]) >= min_distance)
            cows++, last = i;
    return cows;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);
    
    lli begin, end, distance, ans;

    cin >> test_cases;
    while(test_cases--) {
        
        cin >> n_stalls >> n_cows;
        stall.resize(n_stalls);
        for(int i = 0; i < n_stalls; i++)
            cin >> stall[i];

        sort(stall.begin(), stall.end());

        begin = 1, end = 1e9, ans = 0;
        while(begin <= end) {
            distance = begin + ((end - begin) >> 1);
            if(check(distance) >= n_cows)
                begin = distance + 1, ans = distance;
            else
                end = distance - 1;
        }
        cout << ans << endl;
    }

}