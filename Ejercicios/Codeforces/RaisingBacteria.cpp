#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    int n;
    cin >> n;
    cout << __builtin_popcountll( n ) << endl;
    return 0;
}