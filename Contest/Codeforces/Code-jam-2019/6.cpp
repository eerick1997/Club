#include <bits/stdc++.h>

using namespace std;

struct Element{
    string f;
    string s;
    bool visited;
    Element(){
        f = ' ';
        s = ' ';
        visited = false;
    }
};

int main(){
    string str = "", ans = "";
    vector< Element > equivalences;
    equivalences.assign( 5, Element() );
    for( int i = 0; i < 5; i++ ){
        cin >> str;
        if( str[ 1 ] == '>'){
            equivalences[ i ].f = str[ 0 ];
            equivalences[ i ].s = str[ 2 ];
        } else {
            equivalences[ i ].f = str[ 2 ];
            equivalences[ i ].s = str[ 0 ];
        }
    }
    
    ans = (equivalences[ 0 ].f + "") + (equivalences[ 0 ].s + "");
    cout << ans << endl;


    return 0;
}