#include <bits/stdc++.h>

using namespace std;

struct Graph{

    struct Node{
        int value;
        bool visited;
        set< int > adjList;

        Node(){
            value = 0;
            visited = false;
        }

    };

    vector< Node > nodes;

    Graph( int size ){
        nodes.assign( size, Node() );
    }

    void add( int source, int destination ){
        nodes[ source ].adjList.insert( destination );
        nodes[ destination ].adjList.insert( source );
    }

    void setValue( int source, int value ){
        nodes[ source ].value = value;
    }

    int getValue( int source ){
        return nodes[ source ].value;
    }

    void DFS( int source, int destination ){
        nodes[ source ].value = destination;
        nodes[ source ].visited = true;
        set< int >::iterator i;
        for( i = nodes[ source ].adjList.begin(); i != nodes[ source ].adjList.end(); i++ ){
            if( !nodes[ *i ].visited )
                DFS( *i, destination + 1 );
        }
        return;
    }
    
    void print(){
        cout << endl;
        for( int i = 0; i < nodes.size(); i++ )
            cout << i << ' ' << nodes[ i ].value << endl;
        cout << endl;
    }
};

int main(){
    int n_nodes, n_edges;
    int source, destination;

    cin >> n_nodes >> n_edges;
    Graph graph( n_nodes );
    while( n_edges-- ){
        cin >> source >> destination;
        graph.add(source, destination);
    }

    graph.print();

    graph.DFS(0, 0);

    graph.print();

    
}   