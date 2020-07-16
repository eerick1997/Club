#include <bits/stdc++.h>

using namespace std;
using lli = long long int;
int time_desk[100001];

lli check(lli min_time, lli size) {
    lli people = 0;
    for(lli i = 0; i < size; i++)
        people += min_time / time_desk[i];
    return people;
}

lli binary_search(lli begin, lli end, lli n_people, lli n_desks) {
    lli min_time, ans;
    while(begin <= end) {
        min_time = begin + ((end - begin) >> 1);
        if(check(min_time, n_desks) < n_people)
            begin = min_time + 1;
        else 
            end = min_time - 1, ans = min_time;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);   
    lli n_desks, n_people;

    cin >> n_desks >> n_people;
    
    for(lli i = 0; i < n_desks; i++)
        cin >> time_desk[i];

    cout << binary_search(1, 1e15, n_people, n_desks) << "\n";
    return 0;
}