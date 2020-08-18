#include <bits/stdc++.h>

using namespace std;

/**
    Notes:
        -Lose = make a sum
        -Win  = make a substraction
**/
int luckBalance(int n_contests_can_lose, vector<vector<int>> contests) {
    sort(contests.begin(), contests.end());
    int ans = 0;
    for(int i = contests.size() - 1; i >= 0; i--) {
        const auto contest = contests[i];
        //If contest is not important I can lose it
        if(!contest[1])
            ans += contest[0];
        //The contest is importan I can lose just k;
        else if(n_contests_can_lose > 0)
            ans += contest[0], n_contests_can_lose--;
        else 
            ans -= contest[0];

    }
    return ans;
}

int main() {
    int n_preliminary_contests, n_max_contest_can_lose;
    vector<vector<int>> contests;
    cin >> n_preliminary_contests >> n_max_contest_can_lose;
    contests.assign(n_preliminary_contests, {0, 0});

    for(int i = 0; i < n_preliminary_contests; i++)
        cin >> contests[i][0] >> contests[i][1];

    cout << luckBalance(n_max_contest_can_lose, contests) << endl;

    return 0;
}