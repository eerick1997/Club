#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    
    int n, m, aux = 0;
    vector<int> ni, mi;
    
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        aux += a;
        ni.push_back(aux);
    }
    
    cin>>m;
    while(m--){
        int a;
        cin>>a;
        mi.push_back(a);
    }
    
    for(int i = 0; i < mi.size(); i++){
            int val = mi[i];
            int begin = 0, end = ni.size(), middle = 0, res = -1;
            
            while(begin <= end){
                
                middle = (begin + end) / 2;
                
                if(val > ni[middle]){
                    
                    begin = middle + 1;
                    
                } else {
                    
                    end = middle - 1;
                    res = middle;
                    
                }
            }
            
            cout<<"\n"<<++res<<endl;
    }
    
}
