#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector< pair<int, int> > ns;
    cin >> n;
    ns.resize(n);
    for(int i = 0; i < n; i++){
        cin >> ns[i].first;
        ns[i].second = i;
    }
    
    sort(ns.begin(), ns.end());

    int dif = 0;
    pair<int, int> A, B;
    for(int i = 1; i < n; i++){
        if(ns[i - 1].first != ns[i].first){
            dif++;
            A = ns[i - 1];
            B = ns[i];
        }
    }
    
    cout << "\n" << dif << endl;
    cout << A.first <<  endl;
    cout << B.first << endl;


    int ml = abs(ns[0].first - ns[n - 1].first) / 2;
    if(dif == 0)
        cout << "Exemplary pages." << endl;
    else if( dif > 2 || ml == 0 ){
        cout << "Unrecoverable configuration." << endl;
    } else {
        cout << ml << " ml. from cup #" << ns[0].second + 1 << " to cup #" << ns[n - 1].second + 1 << "." << endl;
    }


    return 0;
}