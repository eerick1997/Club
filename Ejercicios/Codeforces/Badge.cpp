#include <bits/stdc++.h>

using namespace std;

struct Graph{

    struct Node{
        bool visited;
        vector< int > adjList;
        Node(){
            this -> visited = false;
        }
    };

    vector< Node > nodes;
    int size;

    Graph( int size ){
        this -> size = size;
        nodes.assign( size, Node() );
    }

    void Connect( int from, int to ){
        nodes[ from ].adjList.push_back( to );
    }

    void DFS( int u ){
        int v;
        nodes[ u ].visited = true;
        for( int i = 0; i < nodes[ u ].adjList.size(); i++ ){
            v = nodes[ u ].adjList[ i ];
            if( !nodes[ v ].visited )
                DFS( v );
            else 
                cout << v << " ";
        }
    }

    

};

int main(){

    int n, x = 1, y = 1;
    Graph graph( 1001 );
    cin >> n;   
    for( int i = 0; i < n; i++ ){
        x = y;
        cin >> y;
        if( y != 1 )
            graph.Connect( x, y );
    }

    for( int a = 1; a <= n; a++ ){
        graph.DFS( a );
    }
    cout << '\n';
    return 0;
}