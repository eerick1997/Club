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

    vector< Node > graph_top_bottom;
    vector< Node > graph_bottom_top;
    vector< pair< int, int > > leafs; 
    vector< int > members;
    int number_nodes;

    Graph( int number_nodes ){
        this -> number_nodes = number_nodes;
        graph_top_bottom.assign( number_nodes, Node() );
        graph_bottom_top.assign( number_nodes, Node() );
    }

    void join( int from, int to ){
        
        graph_top_bottom[ from ].adjList.push_back( to );

        graph_bottom_top[ to ].adjList.push_back( from );

    }

    void getLeaf( int u, int deepth ){
        graph_top_bottom[ u ].visited = true;

        for( int i = 0; i < graph_top_bottom[ u ].adjList.size(); i++ ){
            
            int v = graph_top_bottom[ u ].adjList[ i ];
            if( !graph_top_bottom[ v ].visited )
                getLeaf( v, deepth + 1 );
        }

        if( graph_top_bottom[ u ].adjList.size() == 0 )
            leafs.push_back( { deepth, u } );
    }

    int DFS( int u, int deepth ){
        graph_bottom_top[ u ].visited = true;
        for( int i = 0; i < graph_bottom_top[ u ].adjList.size(); i++ ){
            int v = graph_bottom_top[ u ].adjList[ i ];
            if( !graph_bottom_top[ v ].visited )
                return max( deepth, DFS( v, deepth + 1 ) );
        }
        return deepth;
    }

    int getAns( int maxMembersCanSee ){
        
        int ans = 0;

        sort( leafs.begin(), leafs.end() );
        reverse( leafs.begin(), leafs.end() );

        for( int i = 0; i < leafs.size(); i++ )
            members.push_back( DFS( leafs[ i ].second, 1 ) );

        sort( members.begin(), members.end() );
        reverse( members.begin(), members.end() );

        for( int i = 0; i < maxMembersCanSee; i++ )
            ans += members[ i ];

        return ans;
    }

};

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    int mafiaMembers, maxMembersCanSee;
    cin >> mafiaMembers >> maxMembersCanSee;
    Graph graph( mafiaMembers + 5 );

    for( int i = 2, v; i <= mafiaMembers; i++ ){
        cin >> v;
        graph.join( v, i );
    }

    graph.getLeaf( 1, 0 );
    cout << graph.getAns( maxMembersCanSee ) << endl;
    return 0;
}