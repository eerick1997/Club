#include<bits/stdc++.h>

using namespace std;

/****       DP          ****/
/*
    COIN CHANGE
*/

int CC(int m){
    if( m == 0)
        return 1;
    if( m < 0 )
        return 0;
    if(mem[m] == -1)
        return mem[m];
    for(auto e : a)
        ans += CC(m - e);
    mem[m] = ans;       
    return ans;
}

int CC(int m, int ind){
    if( m == 0)
        return 1;
    if( m < 0 )
        return 0;
    if(mem[m][ind] == -1)
        return mem[m][ind];
    for(int i = ind; i < n; i++)
        ans += CC(m - a[i], i);
    mem[m][ind] = ans;       
    return ans;
}


int CC(int m, int ind){
    if( m == 0)
        return 1;
    if( m < 0 )
        return 0;
    if(mem[m][ind] == -1)
        return mem[m][ind];
    for(int i = ind; i < n; i++)
        ans += CC(m - a[i], i);
    mem[m][ind] = ans;       
    return ans;
}