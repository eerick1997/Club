#include <bits/stdc++.h>

using namespace std;

// Complete the countSwaps function below.
void countSwaps(vector<int> &a) {
    int n_swaps = 0;
    for(int i = 0; i < a.size(); i++)
        for(int j = i + 1; j < a.size(); j++)
            if(a[i] > a[j])
                swap(a[i], a[j]), n_swaps++;

    cout << "Array is sorted in " << n_swaps << " swaps.\n";
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " <<  a[a.size() - 1] << endl;

}

int main() {
    int n;
    vector<int> numbers;
    cin >> n;
    numbers.resize(n);
    for(int i = 0; i < n; i++) 
        cin >> numbers[i];
    
    countSwaps(numbers);
    return 0;
}