#include <iostream>
#include <vector>

#define MAX 10e5

using namespace std;

vector<int> ST(1, (MAX*4) + 1);
vector<int> val(1, MAX);


void createSegment(int begin, int end, int node){

    if(begin == end){
        ST[node] = val[begin];
    } else {
        int middle = ( end + begin ) / 2;
        //Left child
        createSegment(begin, middle, node*2);
        //Right child
        createSegment(middle + 1, end, node * 2 + 1);
        //Making the sign
        ST[node] = ST[node*2]*ST[node*2+1];
    }
}

void update (int begin, int end, int node, int x, int val){
    if(begin == end && begin == x){
        ST[node] = val;
    } else if(begin <= x && x <= end) {
        int middle = (begin + end) / 2;
        update(begin, middle, node*2, x, val);
        update(middle + 1, end, node*2+1, x, val);
        //Making the product
        ST[node] = ST[node*2]*ST[node*2+1];
    }

}

int query (int begin, int end, int node, int i, int j){
    if(end < i || j < begin){
        return 1;
    } else if(i <= begin && end <= j){
        return ST[node];
    } else {
        int middle = (begin + end) / 2;
        int left = query(begin, middle, node, i, j);
        int right = query(middle + 1, end, node, i, j);
        return left * right;
    }
}

int type(int n){
    if(n == 0)
        return 0;
    else if(n > 0)
        return 1;
    else 
        return -1;
}

int main(){
    int I, V, N, K;
    char command;
    cin>>N>>K;
    while(K--){
        int a, b;

        for(int i = 1, n = 0; i <= N; i++){
            cin>>n;
            val[i] = type(n);
        }

        createSegment(1, N, 1);

        cin>>command>>I>>V;
        
        //Change
        if(command == 'C'){
            update(1, N, 1, I, type(V));
        } 
        //Query
        else if(command == 'P'){
            cout<<query(1, N, 1, I, V)<<endl;
        }
        ST.clear();
        val.clear();
    }
}

