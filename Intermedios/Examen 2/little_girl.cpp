#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli input[200002];
lli ST[900002];


void createST(lli node, lli begin, lli end){
    if(begin == end)
        ST[node] = input[begin];
    else {
        lli middle = (begin + end) / 2;
        createST(node * 2, begin, middle);
        createST(node * 2 + 1, middle + 1, end);
        ST[node] = ST[node * 2] + ST[node * 2 + 1];
    }
}

lli query(lli node, lli begin, lli end, lli l, lli r){
    if(end < l || r < begin)
        return 0;
    else if(l <= begin && end <= r){
        return ST[node];
    } else {
        lli middle = (begin + end) /2;
        lli left = query(node * 2, begin, middle, l, r);
        lli right = query((node * 2) + 1, middle + 1, end, l, r);
        return (left + right);
    }
}

int main(){
    
    lli n, q, answ = 0;
    cin>>n>>q;
    for(lli i = 1; i <= n; i++){
        cin>>input[i];
    }
    sort(input, input + (n + 1));
    createST(1, 1, n);
    for(lli i = 1; i <= q; i++){
        lli l, r;
        cin>>l>>r;
        answ += query(1, 1, n, l, r);
    }
    cout<<answ<<endl;
}