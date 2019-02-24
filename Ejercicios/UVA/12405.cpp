#include <bits/stdc++.h>

using namespace std;

//..#..     -> 2
//...#...   -> 2
//.#.       -> 1

int main(){
    char c;
    int T, ans = 0;;
    int N, a = 0, b = 0;
    cin >> T;
    for(int j = 1; j <= T; j++){
        string s;
        cin >> N;
        for(int i = 1; i <= N; i++){
            cin >> c;
            s += c;
        }

        for(int i = 0; i < N; i++){
            if(s[i] == '.')
                a++;
            else 
                b++;
            
            if(a == 3)
                ans++, b = a = 0;
            else if(a == 1 && b == 1 && i < N && s[i + 1] == '.')
                ans++, a = b = 0, i++;
            else if(a > 0 && b > 0)
                ans++, a = b = 0;
        
        }
        ans += (a > 0) ? 1 : 0;
        cout << "Case " << j << ": " << ans << endl;
        ans = a = b = 0;
    }
    return 0;
}