#include <bits/stdc++.h>

using namespace std;

struct Graph{

    struct Node {
        vector<int> neighbors;
        bool visited;
        Node() {
            visited = false;
        }
    };

    vector<Node> adjList;
    Graph(int n_nodes) {
        adjList.resize(n_nodes + 1);
    }

    void add(int u, int v) {
        adjList[u].neighbors.push_back(v);
        adjList[v].neighbors.push_back(u);
    }

    void DFS(int u, int &n_children) {
        adjList[u].visited = true;
        n_children++;
        for(const int v : adjList[u].neighbors)
            if(!adjList[v].visited)
                DFS(v, n_children);
    }

    long roadsAndLibraries(int c_lib, int c_road) {
        int n_cities;
        long ans = 0, build_just_libraries, build_roads;
        for(int i = 1; i < adjList.size(); i++) {
            if(!adjList[i].visited) {
                n_cities = 0, DFS(i, n_cities);
                build_just_libraries = c_lib * (n_cities);
                build_roads = (n_cities - 1) * c_road + c_lib;
                ans += min(build_just_libraries, build_roads);
            }
        }
        return ans;
    }
};



int main() {
    int n_queries, n_cities, n_roads, c_lib, c_road;
    cin >> n_queries;
    while(n_queries--) {
        cin >> n_cities >> n_roads >> c_lib >> c_road;
        Graph graph(n_cities);
        for(int i = 1, u, v; i <= n_roads; i++) {
            cin >> u >> v;
            graph.add(u, v);
        }

        cout << graph.roadsAndLibraries(c_lib, c_road) << endl;
    }
}