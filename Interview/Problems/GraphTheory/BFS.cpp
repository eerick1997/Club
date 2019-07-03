#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;


struct Graph{

    struct Node{
        
        vector< lli > adjList;
        bool visited;
        lli value;

        Node(){
            this -> visited = false;
            this -> value = 0;
        }
    };

    vector< Node > nodes;
    lli size;

    Graph( lli size ){
        this -> size = size;
        nodes.assign( size, Node() );
    }

    void connect( lli from, lli to ){
        nodes[ from ].adjList.push_back( to );
        nodes[ to ].adjList.push_back( from );
    }

    void BFS( lli u ){
        queue< lli > Queue;
        Queue.push( u );

        while( !Queue.empty() ){
            u = Queue.front();
            Queue.pop();
            nodes[ u ].visited = true;
            nodes[ u ].value = 1;

            for( int i = 0; i < nodes[ u ].adjList.size(); i++ ){
                lli v = nodes[ u ].adjList[ i ];
                if( !nodes[ v ].visited )
                    Queue.push( v );
            }

        }

    }

    void print(){
        cout << endl;
        for( int i = 0; i < size; i++ ){
            cout << "node " << i << " value " << nodes[ i ].value << endl;
        }
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

    graph.BFS( 0 );

    graph.print();

    return 0;
}