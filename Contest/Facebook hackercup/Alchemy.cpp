#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    lli n_test_cases, n_shards, nA, nB;
    string shards;
    cin >> n_test_cases;
    for(int test_case = 1; test_case <= n_test_cases; test_case++) {
        nA = nB = 0;
        cin >> n_shards >> shards;
        for(char c : shards) {
            if(c == 'A')
                nA++;
            else 
                nB++;
        }

        cout << "Case #" << test_case << ": " << (abs(nA - nB) > 1 ? 'N' : 'Y') << endl;

    }
    return 0;
}