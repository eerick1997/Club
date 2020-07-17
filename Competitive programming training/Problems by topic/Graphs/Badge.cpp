#include <bits/stdc++.h>

using namespace std;

struct node {
    vector<int> neighbors;
    bool visited;
    node() {
        visited = false;
    }
};

vector<node> graph;

void reset(int size) {
    for(int i = 1; i <= size; i++)
        graph[i].visited = false;
}

int BFS(int u, int size) {
    int v = 0;
    queue<int> Queue;
    reset(size);
    Queue.push(u);
    graph[u].visited = true;
    while(!Queue.empty()) {
        u = Queue.front();
        Queue.pop();
        for(int i = 0; i < graph[u].neighbors.size(); i++){
            v = graph[u].neighbors[i];
            if(!graph[v].visited) {
                graph[v].visited = true;
                Queue.push(v);
            } else 
                return v;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n_students, input;
    cin >> n_students;

    graph.assign(n_students + 1, node());
    for(int i = 1; i <= n_students; i++) {
        cin >> input;
        graph[i].neighbors.push_back(input);
    }

    for(int i = 1; i <= n_students; i++)
        cout << BFS(i, n_students) << " ";
    cout << endl;
}