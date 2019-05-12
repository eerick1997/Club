#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){

    lli N, acum = 0, ans = 0, x = 0;
    cin >> N;
    vector<lli> nums(N + 1);
    unordered_map<lli, lli> A;
    for(int i = 1; i <= N; i++){
        cin >> nums[i];
    }

    for(int i = N; i >= 1; i--){
        acum += nums[i];
        x -= A[nums[i] - 1];
        x += A[nums[i] + 1];

        A[nums[i]]++;
    }

    for(int i = 1; i <= N; i++){
        acum -= nums[i];
        lli aux = acum - (nums[i] * (N - i));
        ans += aux;
    }

    cout << ans - x << endl;
    return 0;
}