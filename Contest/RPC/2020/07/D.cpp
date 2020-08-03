#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

int main() {
    lli test_cases, n_tracks, n_songs_to_listen;
    lli ans = 0;
    vector<lli> track;
    cin >> test_cases;
    while(test_cases--) {
        ios::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
        
        cin >> n_tracks >> n_songs_to_listen;
        track.clear();
        ans = 0;
        track.resize(n_songs_to_listen);

        for(int i = 0; i < n_songs_to_listen; i++) 
            cin >> track[i];

        for(int i = 0; i < n_songs_to_listen - 1; i++) {
            lli forward = 0;
            lli backward = 0;
            if(track[i] > track[i + 1])
                forward = n_tracks - track[i] + track[i + 1];
            else 
                forward = track[i + 1] - track[i];
            
            if(track[i + 1] > track[i])
                backward = track[i] + n_tracks - track[i + 1];
            else 
                backward = track[i] - track[i + 1];

            backward++;
            forward--;

            if(forward < 0)
                ans += backward;
            else if(backward < 0)
                ans += forward;
            else 
                ans += min(backward, forward);
        
        }

        cout << ans << endl;

    }
    return 0;
}