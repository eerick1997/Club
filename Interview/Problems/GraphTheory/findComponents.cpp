#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

struct Graph{
    
    struct Node{
        lli value;
        bool visited;
        lli component;
        vector< lli > adjList;
        Node(){
            value = 0;
            visited = false;
            component = 0;
        }        
    };

    vector< Node > nodes;
    lli size;
    
    Graph( int size ){
        nodes.assign( size, Node() );
        this -> size = size;
    }

    void connect(lli from, lli to){
        nodes[ from ].adjList.push_back( to );
        nodes[ to ].adjList.push_back( from );
    }

    void DFS( lli i, lli count ){
        nodes[ i ].visited = true;
        nodes[ i ].value = 1;
        nodes[ i ].component = count;
        for( int j = 0; j < nodes[ i ].adjList.size(); j++ ){
            lli u = nodes[ i ].adjList[ j ];
            if( !nodes[ u ].visited )
                DFS( u, count );
        }
    }

    lli findComponents(){
        lli count = 0;
        for( int i = 0; i < size; i++ )
            if( !nodes[ i ].visited )
                DFS( i, count++ );
        return count;
    }

    void print(){
        cout << endl;
        for( int i = 0; i < size; i++ )
            cout << i << " " << nodes[ i ].value << endl;
        cout << endl;
    }

};

int main(){
    
    lli n_nodes, n_connections, from, to;
    cin >> n_nodes >> n_connections;
    Graph graph( n_nodes );
    while( n_connections-- ){
        cin >> from >> to;
        graph.connect( from, to );
    }

    graph.print();

    cout << "\n" << graph.findComponents() << "\n\n"; 

    graph.print();
    return 0;
}