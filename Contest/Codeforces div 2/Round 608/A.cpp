#include <bits/stdc++.h>

using namespace std;

int64_t solution( int32_t ties, int32_t scarves, int32_t vests,
                    int32_t jackets, int32_t cost_f, int32_t cost_s) {

    int64_t ans = 0;
    for( int i = 0; i < jackets; i++ ){

        if( ties > 0 && scarves > 0 && vests > 0){
            if( cost_f > cost_s){
                ans += cost_f;
                ties--;
            } else {
                ans += cost_s;
                scarves--, vests--;
            }
        }
        else if( ties > 0 )
            ans += cost_f, ties--;
        else if( scarves > 0 && vests > 0 )
            ans += cost_s, scarves--, vests--;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    int64_t first, second, ans = 0;
    int32_t ties, scarves, vests, jackets, cost_f, cost_s;
    cin >> ties >> scarves >> vests >> jackets >> cost_f >> cost_s;

    cout << solution( ties, scarves, vests, jackets, cost_f, cost_s ) << endl;
}