#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, min_01, min_02 = INT_MAX;
    vector<int> numbers;
    cin >> n;
    numbers.resize(n, 0);
    for(int i = 0; i < n; i++)
        cin >> numbers[i];

    sort( numbers.begin(), numbers.end() );

    min_01 = numbers[n - 1];
    
    for(int i = n - 2; i >= 0; i--){
        if(min_01 != numbers[i]){
            min_02 = numbers[i];
            break;
        }
    }

    cout << ( min_02 == INT_MAX ? "none" : to_string(min_02) ) << endl;
    return 0;
}