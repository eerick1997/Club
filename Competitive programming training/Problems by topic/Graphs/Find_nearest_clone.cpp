#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
struct Graph{
    struct Node {
        long color;
        bool visited;
        vector<int> neighbors;
        Node() {
            color = visited = 0;
        }
    };

    int n_nodes;
    vector<Node> adjList;

    Graph(int n){
        n_nodes = n + 1;
        adjList.assign(n_nodes, Node());
    }

    void add(int node_u, int node_v) {
        adjList[node_u].neighbors.push_back(node_v);
        adjList[node_v].neighbors.push_back(node_u);
    }

    void setColor(int node, int color) {
        adjList[node].color = color;
    }

    void resetVisited() {
        for(Node current_node : adjList) 
            current_node.visited = false;
    }

    bool isTheSameColor(const int a, const int b){
        return ((adjList[a].color == adjList[b].color) and (a != b));
    }

    long BFS(int start) {
        queue<int> Queue;
        int current_node;
        int n_nodes_current_level = 1;
        int n_nodes_next_level = 0;
        int distance = 0;
        adjList[start].visited = true;
        Queue.push(start);
        while(!Queue.empty()) {
            current_node = Queue.front();
            Queue.pop();

            if(isTheSameColor(start, current_node))
                return distance;

            for(const int next_node : adjList[current_node].neighbors){
                if(!adjList[next_node].visited){
                    n_nodes_next_level++;
                    Queue.push(next_node);
                    adjList[next_node].visited = true;
                }
            }
            n_nodes_current_level--;
            if(n_nodes_current_level == 0){
                n_nodes_current_level = n_nodes_next_level;
                n_nodes_next_level = 0;
                distance++;
            }

        }
        return 1e7;
    }

    void printNodes() {
        for(int i = 1; i < n_nodes; i++) {
            for(const int node : adjList[i].neighbors)
                cout << "from " << i << " to " << node << " from color = " << adjList[i].color << endl;
        }
    }

    int shortestPath(int target) {
        long ans = 1e7;
        for(int current_node = 1; current_node < n_nodes; current_node++)
            if(adjList[current_node].color == target)
                ans = min(ans, BFS(current_node));
        return ans == 1e7 ? -1 : ans;
    }
};



int findShortest(int graph_nodes, vector<int> &graph_from, vector<int> &graph_to, vector<long> &ids, int val) {
    //Building graph
    Graph graph(graph_nodes);
    for(int i = 0; i < graph_from.size(); i++)
        graph.add(graph_from[i], graph_to[i]);
    
    for(int i = 0; i < ids.size(); i++)
        graph.setColor(i + 1, ids[i]);
    
    //graph.printNodes();

    return graph.shortestPath(val);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
