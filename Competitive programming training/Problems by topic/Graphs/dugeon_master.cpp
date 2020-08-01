#include <bits/stdc++.h>

using namespace std;
using floor = vector<string>;
vector<floor> dungeon;

int main() {
    int n_test_cases, n_lines, n_columns;
    while(cin >> n_test_cases >> n_lines >> n_columns and n_test_cases and n_lines and n_columns) {
        dungeon.assign(n_test_cases, floor(n_lines));
        for(int i = 0; i < n_test_cases; i++) 
            for(int j = 0; j < n_lines; j++)
                cin >> dungeon[i][j];


    } 
}