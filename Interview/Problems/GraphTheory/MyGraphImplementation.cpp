#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector< lli > vi;

/* A graph is a set of vertices and edges. Also we need to know that
    we can represent a graph using:
    -> An adjacency matrix G[u][v] = w
    -> An adjacency list u -> (v, w)
    -> An edge list (u, v, w)
    To this implementation I've used an adjacency list
 */
struct Graph{

    /* As I mentioned before I'm using an adjacency list, so each
        node has an adjacency list, and each node has it's value and it's
        visited state
     */
    struct Node{

        bool visited;
        lli value;
        vi adjList;

        Node(){
            value = 0;
            visited = false;
        }
    };

    //Set of nodes
    vector< Node > nodes;
    lli size;

    Graph( lli size ){
        this -> size = size;
        nodes.assign( size, Node() );
    }

    /* This function connects a node to our graph
    @param: (lli)from: the source node
    @param: (lli)to: the destination node 
    @return: nothing    */
    void connect(lli from, lli to){
        nodes[ from ].adjList.push_back( to );
        nodes[ to ].adjList.push_back( from );
    }

    /* This function makes a Depth First Search
    @param: (lli)i: the index of the node to search 
    @return: nothing    */
    void DFS( lli i ){
        nodes[ i ].visited = true;
        //This line is using to verify if the DFS made is correct
        nodes[ i ].value = 1;
        for(int j = 0; j < nodes[ i ].adjList.size(); j++){
            lli u = nodes[ i ].adjList[ j ];
            if( !nodes[ u ].visited )
                DFS( u );
        }
    }    

    void print(){
        cout << endl;
        for( int i = 0; i < nodes.size(); i++){
            cout << i << " " << nodes[ i ].value << endl;
        }
        cout << endl;
    }
};

int main(){

    lli n_nodes, n_connections, from, to;
    
    cin >> n_nodes >> n_connections;
    Graph graph( n_nodes );
    while(n_connections--){
        cin >> from >> to;
        graph.connect( from, to );
    }

    graph.print();

    graph.DFS( 0 );

    graph.print();
    
    return 0;
}
