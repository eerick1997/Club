#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Graph {
    private:
        class Node {
            public:
                bool visited;
                vector<int> neighbors;
                Node() {
                    visited = false;
                }
        };
        vector<Node> adjList;
        int n_nodes;

    public:
        Graph(int n) {
            n_nodes = n;
            adjList.assign(n_nodes, Node());
        }
    
        void add_edge(int u, int v) {
            adjList[u].neighbors.push_back(v);
            adjList[v].neighbors.push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            int current_node;
            int depth, n_current_nodes, n_nodes_next_level;
            vector<int> depth_node(n_nodes, -1);

            depth = n_nodes_next_level = 0;
            n_current_nodes = 1;

            queue<int> Queue; 
            Queue.push(start);
            adjList[start].visited = true;

            while(!Queue.empty()) {
                current_node = Queue.front();
                Queue.pop();
                for(const int next_node : adjList[current_node].neighbors){
                    if(!adjList[next_node].visited) {
                        n_nodes_next_level++;
                        Queue.push(next_node);
                        adjList[next_node].visited = true;
                    }
                }

                //Storing the current depth
                if(current_node != start)
                    depth_node[current_node] = 6 * depth;

                n_current_nodes--;
                if(n_current_nodes == 0) {
                    n_current_nodes = n_nodes_next_level;
                    n_nodes_next_level = 0;
                    depth++;
                }

            }
            return depth_node;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
