#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    int t, n;
    string str;
    cin >> t;
    while( t-- ){
        vector< string > ans;
        string aux = "0";
        cin >> n >> str;
        for( int i = 0; i < n - 1; i++){
            if( str[ i ] - '0' > str[ i + 1 ] - '0' ){
                ans.push_back( string( str[ i ] + "") );
                aux = "0";
            } else {
                if( stoi( str ) == 0 )
                    str = string( str[ i ] + "");
                else 
                    str += string( str[ i ] + "");
                if( stoi( str ) < str[ i ] - '0' ){
                    ans.push_back( str );
                    aux = "0";
                }
            }

        }
    }

    return 0;
}