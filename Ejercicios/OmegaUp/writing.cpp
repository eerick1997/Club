#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int g, s;
    vector<int> bucket1(302, 0);
    vector<int> bucket2(302, 0);
    string S, W;
    cin >> g >> s >> S >> W;

    for(int i = 0; i < S.size(); i++)
        bucket1[ S[i] ]++, bucket2[ W[i] ]++;

    int equal = 0;
    for(int i = 0; i < 300; i++){
        if(bucket1[i] == bucket2[i])
            equal++;
    }
    
    int ans = 0;
    if (equal == 300)
        ans++;

    for(int i = 0; g + i < W.size(); i++){

        bool wereEqual = (bucket1[ W[i] ] == bucket2[ W[i] ]);
        bucket2[ W[i] ]--;
        bool areEqual = (bucket1[ W[i] ] == bucket2[ W[i] ]);

        if(wereEqual)
            equal--;
        else if(areEqual)
            equal++;
            
        wereEqual = (bucket1[ W[g + i] ] == bucket2[ W[g + i] ]);
        bucket2[ W[g + i] ]++;
        areEqual = (bucket1[ W[g + i] ] == bucket2[ W[g + i] ]);

        if(wereEqual)
            equal--;
        else if(areEqual)
            equal++;

        if(equal == 300)
            ans++;
    }

    cout << ans << "\n";
}