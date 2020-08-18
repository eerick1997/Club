#include <bits/stdc++.h>

using namespace std;

struct Graph {
    struct Node {
        long id;
        int color;
        bool visited;
        vector<long> neighbors;
        Node() {
            id = color = visited = 0;
        }
    };

    vector<Node> adjList;
    int n_nodes;

    Graph() : n_nodes(n_nodes){
        adjList.resize(n_nodes + 1, Node());
    }

    void add(int u, int v) {
        adjList[u].neighbors.push_back(v);
        adjList[v].neighbors.push_back(u);
    }

    void BFS(long u, int target_color) {
        Queue<int> queue;
        queue.push(u);
        nodes[u].visited = true;
        while(!queue.empty()) {
            u = queue.front();
            queue.pop();
            for(const Node v : adjList[u].neighbors) {
                if(!adjList[v].visited) {
                    adjList[v].visited = true;
                    queue.push(v);
                }
            }
        }
    }

    int findShortest(int val) {
        for(int i = 1; i < n_nodes; i++) {
            if(nodes[i].id == val) {
                BFS(i, )
            }
        }
    }

};

int main() {

    return 0;
}