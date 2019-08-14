#include <bits/stdc++.h>

using namespace std;

struct Graph{

    struct Node{
        bool visited;
        vector< long long int > adjList;
        Node(){
            this -> visited = false;
        }
    };

    vector<Node> nodes;
    int size;
    Graph( int size ){
        this -> size = size;   
        nodes.assign( size + 1, Node() );
    }

    void Connect( int from, int to){
        nodes[ from ].adjList.push_back( to );
        nodes[ to ].adjList.push_back( from );
    }

    void DFS( int u, long long int &n_nodes ){
        nodes[ u ].visited = true;
        for( int i = 0; i < nodes[ u ].adjList.size(); i++){
            long long int v = nodes[ u ].adjList[ i ] ;
            if( !nodes[v].visited ){
                DFS( v, n_nodes );
                n_nodes++;
            }
        }
    }

    long long int solution( int c_lib, int c_road ){
        long long int n_nodes = 0, ans = 0;
        for( int i = 1; i < nodes.size(); i++ ){
            n_nodes = 0;
            if( !nodes[i].visited ){    
                DFS( i, n_nodes );
                ans += min( ( (n_nodes + 1) * c_lib ), ( ( n_nodes ) * c_road ) + c_lib );
            }
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    long long int t, m, n, c_lib, c_road, from, to;
    cin >> t;
    while( t-- ){
        cin >> n >> m >> c_lib >> c_road;
        Graph graph( n );
        for( int i = 0; i < m; i++ ){
            cin >> from >> to;
            graph.Connect( from, to );
        }
        cout << graph.solution( c_lib, c_road ) << endl;
    }
    return 0;
}