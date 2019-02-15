#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
int main(){
    lli n, ans = 0;
    vector<lli> numbers;
    cin >> n;
    numbers.resize(n);
    for(int i = 0; i < n; i++)
        cin >> numbers[i];
    sort(numbers.begin(), numbers.end());

    for(int i = 0; i < (n / 2); i++){
        ans += pow( (numbers[i] + numbers[n - i - 1]), 2);
    }
    cout << ans << endl;
}