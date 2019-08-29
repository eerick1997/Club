#include <bits/stdc++.h>

using namespace std;

int main(){
    int q, n;
    int sum = 0, division = 0;
    string current_num, str, numbers;
    cin >> q;
    while( q-- ){
        sum = division = 0;
        vector< string > ans;
        str = "0";
        cin >> n;
        cin >> numbers;
        for( int i = 0; i < n - 1; i++ ){
            
            if( ans.size() > 0 ){
                if( numbers[ i ] - '0' > numbers[ i + 1 ] - '0' ){
                    string aux = "";
                    aux += numbers[ i ];
                    ans.push_back( aux );
                    str = "0";
                } else {
                    
                    if( stoi( str ) == 0)
                        str = numbers[ i ];
                    else 
                        str += numbers[ i ];

                    if( stoi( str ) > stoi( ans[ ans.size() - 1 ] ) ){
                        ans.push_back( str );
                        str = "0";
                    }
                }

            } else {
                if( stoi( str ) == 0)
                        str = numbers[ i ];
                    else 
                        str += numbers[ i ];

                    if( stoi( str ) > numbers[ i ]){
                        ans.push_back( str );
                        str = "0";
                }
            }
            
        }
    
        if( ans.size() > 0 ){
            cout << "\nYES" << endl;
            for( auto e : ans )
                cout << e << " ";
            cout << endl;
        } else 
            cout << "NO" << endl;
        
    }
    return 0;
}