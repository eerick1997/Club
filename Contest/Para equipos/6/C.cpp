#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;
    vector< pair<int, int> > V(s.size() * 2);
    vector<int> ans;
    if( (s.size() % 2) != 0){
        cout << "NO" << endl;
    } else {

       for(int i = 0; i < s.size(); i++){
           pair<int, int> node;
           
           if(s[i % s.size()] == 'A'){

               if(i == 0) {
                   node.first = 1;
                   node.second = 0;
                   V[i] = node;
               } else {
                   node.first += 1 + V[i - 1].first;
                   node.second += V[i - 1].second;
               }

           } else {
               if(i == 0) {
                   node.first = 0;
                   node.second = 1;
                   V[i] = node;
               } else {
                   node.first = V[i - 1].first;
                   node.second = 1 + V[i - 1].second;
               }
           }

       }

       for(int i = s.size(); i < s.size() * 2; i++)
           V[i] = V[i - s.size()];
       
       for(int i = 0; i < )

    }
    return 0;
}