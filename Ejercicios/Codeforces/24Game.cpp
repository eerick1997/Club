#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    if( n <= 3 )   
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        if( n == 4 ){
            cout << "4 * 3 = 12\n";
            cout << "2 * 12 = 24\n";
            cout << "1 * 24 = 24\n";
        } else if( n == 5 ){
            cout << "5 * 4 = 20\n";
            cout << "3 - 1 = 2\n";
            cout << "2 + 3 = 4\n";
            cout << "4 + 20 = 24\n";
        } else {
            for( int i = 1; i < n - 2; i++ )
                cout << i << " - " << ( i - 1 ) << " = 1\n";
            cout << 24 << " * " << " 1 = 24\n";
        }
    }
    return 0;
}