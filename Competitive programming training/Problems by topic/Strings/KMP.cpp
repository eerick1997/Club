#include <bits/stdc++.h>

using namespace std;

int main() {
    string str, target;
    vector<int> table;

    cin >> str >> target;
    table.resize(target.size() + 1, 0);

    //Fill the table
    for(int right = 1, left = 0; right < target.size(); right++) {
        if(target[right] == target[left])
            table[right + 1] = table[right] + 1, left++;
        else 
            left = 0;
    }

    for(const int num : table)
        cout << num << " ";
    
    cout << endl;

    //Matching
    for(int i = 0, j = 0; i < str.size(); i++) {
        
        if(str[i] == target[j])
            j++;
        else 
            j = table[j + 1];

        if(j == target.size()) {
            cout << "Found = " << target << endl;
            break;
        }
    }
    
    return 0;
}