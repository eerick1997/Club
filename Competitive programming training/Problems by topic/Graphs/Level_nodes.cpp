#include <bits/stdc++.h>

using namespace std;

struct node {
    bool visited;
    int level;
    vector<int> neighbors;
    node() : visited(false){}
};

vector<node> graph;

void add(int u, int v) {
    graph[u].neighbors.push_back(v);
}

int BFS(int u, int target) {
    int v, level = 1;
    int current_nodes = 1;
    int next_nodes = 0;
    queue<int> Queue;
    Queue.push(u);
    graph[u].visited = true;
    while(!Queue.empty()) {
        
        u = Queue.front();
        Queue.pop();
        
        next_nodes += graph[u].neighbors.size();

        if((--current_nodes) == 0)
            current_nodes = next_nodes, next_nodes = 0, level++;
        
        if(level > target)
            return current_nodes;
            
        for(int i = 0; i < graph[u].neighbors.size(); i++) {
            v = graph[u].neighbors[i];
            if(!graph[v].visited) {
                graph[v].visited = true;
                Queue.push(v);
            }
        }
    }
    return 0;
}

void DFS(int u, int target, int level) {
    int v;
    graph[u].visited = true;
    for(int i = 0; i < graph[u].neighbors.size(); i++) {
        v = graph[u].neighbors[i];
        if(!graph[v].visited) {
            DFS(v, target, level + 1);
        }
    }
}

int main() {
    int n_nodes, u, v, target;
    cin >> n_nodes;
    graph.resize(n_nodes + 1);

    for(int i = 0; i < n_nodes - 1; i++) {
        cin >> u >> v;
        add(u, v);
    }
    cin >> target;
    cout << BFS(1, target) << endl;

    return 0;
}