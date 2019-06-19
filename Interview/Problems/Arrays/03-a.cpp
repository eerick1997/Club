#include <bits/stdc++.h>

using namespace std;

int main(){

    int m, n;
    vector<int> M, N, ans;

    cin >> m >> n;
    M.resize(m, 0);
    N.resize(n, 0);

    for(int i = 0; i < m; i++)
        cin >> M[i];

    for(int i = 0; i < n; i++)
        cin >> N[i];

    int i = 0, j = 0;
    while( i < m && j < n ){
        if(M[i] < N[j]){
            ans.push_back( M[i++] );
        } else {
            ans.push_back( N[j++] );
        }
    }

    for ( ; i < m; i++)
        ans.push_back( M[i] );

    for( ; j < n; j++)
        ans.push_back( N[j] );

    for( auto e : ans )
        cout << e << " ";
    
    cout << endl;
    return 0;
}