#include <bits/stdc++.h>

/*
    You need to consider the arithmetic sum digits:
    Here you are some information about this:
    http://applet-magic.com/DigitSum.htm

    Fot this problem we need to use the next property
    DigitSum(A*B) = DigitSum( DigitSum(A) * DigitSum(B) )

    Example:
    A = 25 and B = 30
    DigitSum(25 * 30) = DigitSum(750) = 7 + 5 + 0 = 12 = 1 + 2 = 3
    It is equals to:
    DigitSum( DigitSum(25) * DigitSum(30) ) = DigitSum( (2 + 5) * (3 + 0) ) 
    DigitSum( 7 * 3 ) = DigitSum( 21 ) = 2 + 1 = 3
    Therefore both are equals;
 */
using namespace std;

typedef long long int lli;

lli digitSum(string s){

    lli ans = 0;

    for(int i = 0; i < s.size(); i++)
        ans += s[i] - '0';
    
    if(ans > 9) 
        return digitSum( to_string(ans) );
    return ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli RESULT = 0;
    int a, b, p;
    string A, B, P;
    cin >> a >> b >> p;
    cin >> A >> B >> P;

    RESULT = digitSum( to_string( digitSum(A) * digitSum(B) ) );

    auto i = find(begin(P), end(P), '*');

    for(char j = '1'; j <= '9'; j++){
        *i = j;
        if(digitSum(P) == RESULT){
            cout << j << '\n';
            break;
        }
    }
    return 0;
}