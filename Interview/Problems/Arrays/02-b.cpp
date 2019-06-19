#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<int> numbers;
    map<int, int> repeated;
    cin >> n;
    numbers.resize(n, 0);
    for(int i = 0; i < n; i++)
        cin >> numbers[i];

    for(int i = 0; i < n; i++)
        repeated[ numbers[i] ]++;
    
    
    for(auto e : repeated ){
        if(e.second == 1){
            cout << e.first << endl;
            break;
        }
    }
    
    return 0;
}