#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    vector<int> numbers;
    cin >> n;
    numbers.resize(n, 0);
    for(int i = 0; i < n; i++)
        cin >> numbers[i];

    for(int i = 0; i < n; i++) {    

        for(int j = 0; j < n; j++) {

            if(numbers[i] == numbers[j] && i != j)
                break;
            if(j == n - 1){
                cout << numbers[i] << endl;
                exit(0);
            }

        }

    }
    return 0;
}