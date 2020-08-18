#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

int main() {
    int n_trips;
    lli money;
    lli size_array:
    vector<lli> cost;

    cin >> n_trips;
    while(n_trips--) {
        cin >> money >> size_array;
        cost.resize(size_array);
        for(lli &C : cost)
            cin >> C;
        
    }
    return 0;
}