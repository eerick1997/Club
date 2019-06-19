#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    int min_01 = INT_MAX, min_02 = INT_MAX;
    vector<int> numbers;
    cin >> n;
    numbers.resize(n, 0);
    for(int i = 0; i < n; i++)
        cin >> numbers[i];

    for(int i = 0; i < n; i++){
        if(numbers[i] < min_01){
            min_02 = min_01;
            min_01 = numbers[i];
        } else if (numbers[i] < min_02 && numbers[i] != min_01)
            min_02 = numbers[i];
    }

    cout << (min_02 == INT_MAX ? "none" : to_string(min_02)) << endl;
    return 0;
}