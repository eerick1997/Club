#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    int n, i = 0, a = 0; 
    cin >> n;
    while( n-- ){
        cin >> str;
        ++i;
        if( str == "mumble" ){
            continue;
        } 
        
            a = stoi( str );
            if( i != a ){
                cout << "something is fishy" << endl;
                exit( 0 );
            }


    }
    cout << "makes sense" << endl;
    return 0;
}