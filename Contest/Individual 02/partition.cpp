#include <bits/stdc++.h>
// 
using namespace std;

void subsets(vector<int> &num, map<int, int> &ans, int i, int sum){

    if(i == num.size()){
        ans[sum]++;
        return;
    }

    ans[sum]++;

    /*if(ans[sum] > 0){
        ans[sum]++;
        return; 
    }*/

    subsets(num, ans, i + 1, sum + num[i]);
    subsets(num, ans, i + 1, sum);
}

int main(){

    bool r = false;
    vector<int> num;
    map<int, int> ans;
    int k, a;
    cin >> a >> k;
    num.resize(a);
    for(int i = 0; i < a; i++)
        cin >> num[i];

    subsets(num, ans, 0, 0);
    for(map<int, int>::iterator it = ans.begin(); it != ans.end(); it++)
        if(it->second == k && it -> first != 0)
            //cout << "\nfirst " << it->first << " \nsecond " << it->second << endl; 
            r = true;
    cout << ( (r) ? "True" : "False") << endl;


    return 0;
}