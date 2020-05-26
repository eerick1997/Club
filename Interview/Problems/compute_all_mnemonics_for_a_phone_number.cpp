#include <bits/stdc++.h>
/**
    let's call n = length of the input
    Complexity in time O( n * 4^n ) imagine that the input is a string build just for the character 9 so we gonna make 4 forks 
    for each recursive call, and we gonna make 4^n recursive calls in the worst case.

    Complexity in memory O( n + 4^n ) = O( 4^n ), remember we're getting a vector of strings (O(n)) and also we are
    getting a lot of strings one for each combination (O(4^n))
**/
const int asterisk = 10;
const int hashtag = 11;

using namespace std;
using vs = vector< string >;

string dialer[ 12 ] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ", "", "" };

void get_mnemonics( int index, string current_str, string input, vs &ans ) {
    if( input.size() == index ) {
        ans.push_back( current_str );
        return;
    }
    for( auto c : dialer[ input[ index ] - '0' ] )
        get_mnemonics( index + 1, current_str + c, input, ans );

}

int main() {
    vs ans;
    string input;
    cin >> input;
    get_mnemonics( 0, "", input, ans );
    for( auto str : ans )
        cout << str << endl;
    return 0;
}