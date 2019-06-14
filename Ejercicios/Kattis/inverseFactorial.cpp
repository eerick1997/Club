#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int ans = 0;
    string s;
    cin >> s;

    if(s.size() <=  3){
        
        switch( stoi(s) ){
            case 1: 
                ans = 1;
            break;

            case 2:
                ans = 2;
            break;

            case 6:
                ans = 3;
            break;

            case 24:
                ans = 4;
            break;

            case 120:
                ans = 5;
            break;

            case 720:
                ans = 6;
            break;
        }

        cout << ans << "\n";

    } else {
    
        double sum = 0;
        int i;
        for(i = 1; ; i++){
            sum += log10(i);   
            if( ceil(sum) == s.size())
                break;
        }

        cout << i << "\n";
    }
}