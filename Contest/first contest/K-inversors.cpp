#include <bits/stdc++.h>

using namespace std;

void mergeSort(int begin, int end, int middle, string &s, vector<int> &cubeta){
    int i = begin, j = middle + 1;
    while(begin <= middle && middle + 1 <= end){ 
        if(s[i] == 'B' && s[j] == 'A')
            cubeta[j - i]++;
        if(s[i] == 'A')
            i++;
        if(s[j] == 'B')
            j++;
    }
}

void merge(string &s, vector<int> &cubeta){
    
}


int main(){
    string s; 
    cin >> s;
    vector<int> cubeta(s.size() + 10, 0);
    merge();
    merge();
    return 0;
}