#include <bits/stdc++.h>

using namespace std;

int main(){
    double n, h;
    cin >> n >> h;
    for(int i = 1; i < n; i++){
        cout << fixed;
        cout << setprecision(12);
        cout << ( sqrt( i/n ) * h )<< endl;
    }
}