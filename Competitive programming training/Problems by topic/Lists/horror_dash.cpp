#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    int test_cases, students, s_i, ans;
    cin >> test_cases;
    for( int i = 1; i <= test_cases; i++ ) { 
        ans = -1;
        cin >> students;
        while( students-- ) {
            cin >> s_i;
            ans = max( ans, s_i );
        }
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}