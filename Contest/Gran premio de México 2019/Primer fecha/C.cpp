/***
 * TEMA: Grafos
 *      ->Disjoint set
 *      ->Kruskal
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<bool> vb;
int infinite = 1 << 30;

struct disjointSet{
    int N;
    vector<short int> rank;
    vi parent, count;

    disjointSet(int N): N(N), parent(N), count(N), rank(N){}

    void makeSet(int v){
        count[v] = 1;
        parent[v] = v;
    }

    int findSet(int v){
        if(v == parent[v])
            return v;
        return parent[v] = findSet(parent[v]);
    }

    void unionSet(int a, int b){
        a = findSet(a), b = findSet(b);
        if(a == b)
            return;
        if(rank[a] < rank[b]){
            parent[a] = b;
            count[b] += count[a];
        } else {
            parent[b] = a;
            count[a] += count[b];
            if(rank[a] == rank[b])
                ++rank[a];
        }
    }
};

struct edge{
    int source, destination, cost;
    edge(): source(0), destination(0), cost(0){}
    edge(int destination, int cost): destination(destination), cost(cost){}
    edge(int source, int destination, int cost): source(source), destination(destination), cost(cost){}
    bool operator==(const edge &b) const{
        return source == b.source && destination == b.destination && cost == b.cost;
    }

    bool operator<(const edge &b) const{
        return cost < b.cost;
    }

    bool operator>(const edge &b) const{
        return cost > b.cost;
    }
};



int main(){
    
    return 0;
}