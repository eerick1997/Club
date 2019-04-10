#include <bits/stdc++.h>

using namespace std;

bool sortBySecond(const pair<char, int> &a, const pair<char, int> &b){
    return (a.second < b.second);
}


int main(){
    int n;
    vector< pair<char, int> > ans(30);
    string s, ss;
    cin >> n;
    while(n--){    
        cin >> s;
        for(int i = 0; i < s.size(); i++)
            ans[ s[i] - 'A'].second++, ans[ s[i] - 'A' ].first = s[i];
    }

    sort(ans.begin(), ans.end(), sortBySecond);

    int max = ans[ans.size() - 1].second;
    ss = s;
    s = ans[ans.size() - 1].first;
    for(int i = ans.size() - 2; i >= 0; i--){
        if(max == ans[i].second)
            s += ans[i].first;
    }

    sort( s.begin(), s.end() );
    cout << ( (s.size() == 1) ? s : ss ) << endl;
    return 0;
}