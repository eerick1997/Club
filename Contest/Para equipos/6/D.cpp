#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){

    lli T, N, K, m1, m2, ans = 0;
    cin >> T;
    while(T--){
        ans = 0;
        vector< lli > min_prices;
        cin >> N >> K;
        
        for(int i = 0; i < N; i++){
            lli p1, p2, p3;
            cin >> p1 >> p2 >> p3;
            
            if(p1 >= p2 && p1 >= p3)
                m1 = p3, m2 = p2;
            else if(p2 >= p1 && p2 >= p3)
                m1 = p3, m2 = p1;
            else if(p3 >= p1 && p3 >= p2)
                m1 = p1, m2 = p2;            
            
            min_prices.push_back(m1);
            min_prices.push_back(m2);
        }

        sort(min_prices.begin(), min_prices.end());
        
        for(int i = 0, j = 0; i < min_prices.size(); i++){
            if(j != K){
                j++;
                ans += min_prices[i];
            }
        }

        cout << ans << endl;
    }
    return 0;
}