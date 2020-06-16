#include <bits/stdc++.h>

using namespace std;

struct graph {
    struct node {
        int data;
        bool visited;
        set< int > list;
        node(){
            visited = false;
        }
    };

    vector< node > adj_list;
    int size;
    graph( int nsize ) {
        size = nsize;
        adj_list.resize( size );
    }

    void insert( int from, int to ) {
        adj_list[ from ].list.push_back( to );
        adj_list[ to ].list.push_back( brom );
    }

    void DFS( int source, int destination ) {
        adj_list[ source ].visited = true;
        for( int i : adj_list[ source ] ) {
            if( !adj_list[ i ].visited )
                DFS( i, destination );
        }
    }

    void BFS( int source, int destination ) {
        queue< int > Queue;
        adj_list[ source ].visited = true;
        Queue.push_back( source );
        while( !Queue.empty() ){
            int u = Queue.front();
            Queue.pop();
            for( int v : adj_list[ u ].list ) {
                if( !nodes[ v ].visited )
                    Queue.push_back( v );
            }

        }
    }
};

int main() {
    graph Graph( 10 );
    graph.insert( 0, 1 );
    graph.insert( 0, 5 );
    graph.insert( 0, 2 );
    graph.insert( 1, 2 );
    graph.insert( 1, 4 );
    graph.insert( 2, 3 );
    graph.insert( 3, 4 );
    graph.insert( 4, 5 );
        
    return 0;
}