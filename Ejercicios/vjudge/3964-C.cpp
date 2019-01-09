#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
    lli n, A = 0;
    cin >> n;
    while(n > 0){
        A += n % 10;
        n /= 10;
    }
    if(A == 1)
        cout << 10 << endl;
    else
        cout << A << endl;
    return 0;
}