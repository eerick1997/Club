#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
    lli K, N;
    vector<lli> trees;
    cin >> N >> K;
    trees.resize(N, 0);
    
    for(int i = 0; i < N; i++){
        cin >> trees[i];
    }
    sort(trees.begin(), trees.end());
    
    cout << trees[N - 1] - trees[N - K] << endl;
    return 0;
}