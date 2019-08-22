#include <bits/stdc++.h>

using namespace std;

struct Graph{
    struct Node{
        vector< int > adjList;
        bool visited;
        Node(){
            visited = false;
        }
    };

    vector<Node> nodes;
    int size;
    Graph( int size ){
        this -> size = size;
        nodes.assign( size, Node() );
    }

    void connect( int from, int to ){
        nodes[ from ].adjList.push_back( to );
        nodes[ to ].adjList.push_back( from );
    }

    void BFS( int u ){
        queue<int> Queue;
        Queue.push( u );
        while( !Queue.empty() ){
            u = Queue.front();
            nodes[ u ].visited = true;
            for( int i = 0; i < nodes[ u ].adjList.size(); i++ ){
                int v = nodes[ u ].adjList[ i ];
                if( !nodes[ v ].visited ){
                    Queue.push( v );
                }
            }
        }
    }

    void BFS( int u, vector<int> &path){
        queue<int> Queue;
        Queue.push( u );
        while( !Queue.empty() ){
            u = Queue.front();
            nodes[ u ].visited = true;
            for( int i = 0; i < nodes[ u ].adjList.size(); i++ ){
                int v = nodes[ u ].adjList[ i ];
                if( !nodes[v].visited ){
                    path[ v ] = u;
                    Queue.push( v );
                }
            }
        }
    }

    vector< int > shortestPath( int from, int to ){
        vector< int > path( nodes.size(), -1 );
        vector< int > ans;
        BFS( from, path );
        int v = to;
        while( path[ v ] != -1 ){
            ans.push_back( v );
            v = path[ v ];
        }
        return ans;
    }
};

int main(){

    Graph graph( 12 );
    graph.connect(1, 3);
    graph.connect(2, 3);
    graph.connect(3, 4);
    graph.connect(3, 5);
    graph.connect(4, 6);
    graph.connect(5, 6);
    graph.connect(6, 7);
    graph.connect(5, 8);
    graph.connect(7, 9);
    graph.connect(8, 9);
    graph.BFS( 1 );
    /*vector< int > path = graph.shortestPath(1, 9);
    for( int e : path )
        cout << e << " ";*/
}