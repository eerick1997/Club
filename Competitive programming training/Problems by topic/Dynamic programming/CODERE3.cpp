#include <bits/stdc++.h>

using namespace std;
using lli = long long int;
int n_elements;

vector<lli> buildings;

lli solve() {
    vector<lli> DPLtoR(n_elements);
    vector<lli> DPRtoL(n_elements);

    for(int j = 0; j < n_elements; j++)
        for(int i = 0; i < j; i++)
            if(buildings[j] > buildings[i])
                DPLtoR[j] = max(DPLtoR[j], DPLtoR[i] + 1);
    
    for(int j = n_elements - 1; j >= 0; j--)
        for(int i = n_elements - 1; i > j; i--)
            if(buildings[j] > buildings[i])
                DPRtoL[j] = max(DPRtoL[j], DPRtoL[i] + 1);

    lli ans = -1;
    for(int i = 0; i < n_elements; i++)
        ans = max(ans, DPRtoL[i] + DPLtoR[i] + 1);
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while(test_cases--) {
        cin >> n_elements;
        buildings.resize(n_elements);
        for(int i = 0; i < n_elements; i++)
            cin >> buildings[i];
        cout << solve() << endl;
        buildings.clear();
    }
    return 0;
}