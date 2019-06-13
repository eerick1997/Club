#include <bits/stdc++.h>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string day;
    int N = 0, X = 0, AQI = 0, iday = 0, ans = 0;
    cin >> N >> day >> X;

    if(day == "Monday"){
        iday = 0;
    } else if (day == "Tuesday"){
        iday = 1;
    } else if(day == "Wednesday"){
        iday = 2;
    } else if(day == "Thursday"){
        iday = 3;
    } else if(day == "Friday"){
        iday = 4;
    } else if(day == "Saturday"){
        iday = 5;
    } else {
        iday = 6;
    }

    for(int i = 0; i < N; i++, (++iday %= 7) ) {
        cin >> AQI;
        if(AQI >= X && (iday != 5 && iday != 6) )
            ans++;
    }
        
    cout << ans << '\n';

    return 0;
}