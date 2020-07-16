#include <bits/stdc++.h>

using namespace std;
using lli = long long int;
vector<lli> marble;

lli binary_search(lli begin, lli end, lli target) {
    lli middle, ans = 0;
    while(begin <= end) {
        middle = begin + ((end - begin) >> 1);
        if(marble[middle] >= target)
            end = middle - 1, ans = middle;
        else 
            begin = middle + 1;
    }
    return (marble[ans] != target ? -1 : ans + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    lli n_marbles, n_queries, ans, query, n_case = 0;

    while(cin >> n_marbles >> n_queries and n_marbles and n_queries) {
        n_case++;
        ans = -1;
        marble.resize(n_marbles);
        for(int i = 0; i < n_marbles; i++)
            cin >> marble[i];
        
        sort(marble.begin(), marble.end());

        cout << "CASE# " << n_case << ":\n";
        while(n_queries--) {
            cin >> query;

            ans = binary_search(0, n_marbles - 1, query);
    
            if(ans != -1)
                cout << query << " found at " << ans << endl;
            else    
                cout << query << " not found" << endl;
        }
        marble.clear();
    }
    return 0;
}