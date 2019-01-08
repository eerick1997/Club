#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

struct nodeST{
    int n;
    int m;
};

lli arr[100002];
nodeST  ST[300002];

void updateST(int node, int begin, int end, int position, int value){
    if(begin == end && begin == position){
        ST[node].n = value;
        ST[node].m = -1;
    } else if(begin <= position && position <= end){
        int middle = (begin + end) >> 1;
        updateST(node * 2, begin, middle, position, value);
        updateST(node * 2 + 1, middle + 1, end, position, value);
        ST[node].n = max(ST[node * 2].n, ST[node * 2 + 1].n);
        ST[node].m = min(max(ST[node * 2].n, ST[node * 2 + 1].m),
                         max(ST[node * 2].m, ST[node * 2 + 1].n) );
    }
}

nodeST queryST(int node, int begin, int end, int left, int right){
    if(end < left || right < begin){
        nodeST def;
        def.n = def.m = -1;
        return def;
    } else if(left <= begin && end <= right)
        return ST[node];
    else {
        int middle = ( begin + end ) >> 1;
        nodeST left_value = queryST(node * 2, begin, middle, left, right);
        nodeST right_value = queryST(node * 2 + 1, middle + 1, end, left, right);
        nodeST ans;
        ans.n= max(left_value.n, right_value.n);
        ans.m = min(max(left_value.n, right_value.m),
                    max(left_value.m, right_value.n));
        return ans;
    }
}

void buildST(int node, int begin, int end){
    if(begin == end){
        ST[node].n = arr[begin];
        ST[node].m = -1;
    } else {
        int middle = (begin + end) >> 1;
        buildST(node * 2, begin, middle);
        buildST(node * 2 + 1, middle + 1, end);
        ST[node].n = max(ST[node * 2].n, ST[node * 2 + 1].n);
        ST[node].m = min( max(ST[node * 2].n, ST[node * 2 + 1].m),
                          max(ST[node * 2].m, ST[node * 2 + 1].n) );
    }
}

int main(){
    int N, Q, L, R;
    char OP;

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    
    cin >> Q;
    buildST(1, 1, N);

    for(int i = 1; i <= Q; i++){
        cin >> OP >> L >> R;
        if(OP == 'Q'){
            nodeST ans = queryST(1, 1, N, L, R);
            cout << (ans.n + ans.m) << endl;
        } else {
            //l position
            //r value
            updateST(1, 1, N, L, R);
        }
    }
    return 0;
} 