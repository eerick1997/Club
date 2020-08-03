#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    lli initial_rate, additional_rate;
    lli n_persons, energy_consumption;
    lli ans = 0;
    lli extra_energy;
    cin  >> initial_rate >> additional_rate;
    cin >> n_persons;
    while(n_persons--) {
        cin >> energy_consumption;
        if(energy_consumption <= 1000)
            ans = energy_consumption * initial_rate;
        else {
            ans = initial_rate * 1000;
            ans += (energy_consumption - 1000) * additional_rate;
        }


        cout << energy_consumption << " " << ans << endl; 

    }
}