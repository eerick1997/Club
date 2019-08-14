//Complexity O(n)
#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( 0 );
    cout.tie( 0 );
    cin.tie( 0 );

    int n;
    string ans = "0000000000";
    char event;
    cin >> n;
    //Note use getchar() makes TLE
    while( n-- ){
        cin >> event;
        //A customer arrives from the left entrance
        if( event == 'L' ){
            for( int i = 0; i < ans.size(); i++ ){
                if( ans[ i ] == '0' ){
                    ans[ i ] = '1';
                    break;
                }
            }
        }

        //A customer arrives from the right entrance
        else if( event == 'R'){
            for( int i = ans.size() - 1; i >= 0; i-- ){
                if( ans[ i ] == '0' ){
                    ans[ i ] = '1';
                    break;
                }
            }
        }
        //'0', '1', ... , '9': The customer room x (0, 1, ... , 9 respectly ) leaves
        else {
            ans[ event - '0' ] = '0';
        }
    }

    cout << ans << endl;
    return 0;
}