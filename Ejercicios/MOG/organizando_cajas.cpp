#include <bits/stdc++.h>

using namespace std;

int main(){
    set<int> cajas;
    int n, w, s;
    cin >> n;
    while(n--){
        cin >> w >> s;
        cajas.insert(s);
    }
    cout << cajas.size() << endl;
    return 0;
}