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
            if( str[ i ] - '0' > str[ i + 1 ] - '0' && stoi( aux ) == 0){
                aux = str[ i ];
                ans.push_back( aux );
                aux = "0";
            } else {
                if( stoi( str ) == 0 )
                    aux = str[ i ];
                else 
                    aux += str[ i ];

                if( stoi( aux ) < stoi( ans[ ans.size() - 1 ] ) && ans.size() > 0){
                    ans.push_back( aux );
                    aux = "0";
                }
            }

        }
        for( auto e : ans )
            cout << e << " ";
        cout << endl;
    }

    return 0;
}