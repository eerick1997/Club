#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

struct Graph{

    struct Node{
        lli value;
        bool visited;
        vector< lli > adjList;

        Node(){
            this -> value = 0;
            this -> visited = false;
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

    void BFS( lli from, lli to ){
        queue< lli > Queue;
        Queue.push( from );

        while( !Queue.empty() ){
            from = Queue.front();
            Queue.pop();
            nodes[ from ].visited = true;
            nodes[ from ].value = 1;
            for( int i = 0; i < nodes[ from ].adjList.size(); i++ ){
                lli v = nodes[ from ].adjList[ i ];
                if( !nodes[ v ].visited ){
                    if( nodes[ v ] )
                        Queue.push( v );
                }
            }
        }

    }
};

int main(){

    return 0;
}