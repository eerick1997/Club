#include <bits/stdc++.h>

using namespace std;

struct graph {

    struct node {
        vector< int > list;
        bool visited;
        node() {
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
        adj_list[ to ].list.push_back( from );
    }

    void DFS( int current ) {
        adj_list[ current ].visited = true;
        for( int node : adj_list[ current ].list )
            if( !adj_list[ node ].visited )
                DFS( node );
    }

    vector< int > BFS( int current ) {
        queue< int > Queue;
        vector< int > prev(size, -1);

        Queue.push( current );
        adj_list[ current ].visited = true;
        while( !Queue.empty() ) {
            current = Queue.front();
            Queue.pop();
            vector< int > list = adj_list[ current ].list;

            for( int node : list ){
                if( !adj_list[ node ].visited ) {
                    Queue.push( node );
                    adj_list[ node ].visited = true;
                    prev[ node ] = current;
                }
            }
        }
        return prev;
    }

    vector< int > shortest_path( int source, int target ) {
        vector< int > prev = BFS( source );
        vector< int > path;

        for( int i = source; i > -1; i = prev[ i ] ) {
            cout << i << " ";
            path.push_back( i );
        }
        
        cout << endl;
        reverse( begin( path ), end( path ) );

        if( path[ 0 ] == source )
            return path;
        return {};
    }

    int count_components() {
        int components = 0;
        for( int current = 0; current < size; current++ ) {
            if( !adj_list[ current ].visited ) 
                DFS( current ), components++;
        }
        return components;
    }
};

int main() {
    graph Graph( 12 );
    Graph.insert( 0, 1 );
    Graph.insert( 0, 5 );
    Graph.insert( 0, 2 );
    Graph.insert( 1, 4 );
    Graph.insert( 2, 3 );
    Graph.insert( 4, 6 );
    Graph.insert( 3, 5 );

    Graph.insert( 6, 7 );

    Graph.insert( 8, 9 );
    
    for( auto c : Graph.shortest_path( 0, 5 ) )
        cout << c << " ";
    cout << endl;
    return 0;
}