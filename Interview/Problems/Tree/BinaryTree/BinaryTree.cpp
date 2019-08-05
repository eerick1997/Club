#include <bits/stdc++.h>

using namespace std;

struct BinaryTree{

    struct Node{
        int value;
        Node *left;
        Node *right;
        
        Node( int value ){
            this -> value = value;
            left = right = NULL;
        }
    };
    
    Node *root;
    
    BinaryTree(){
        root = NULL;
    }

    void Insert( int value ){
        root = Insert( root, value );
    }

    Node *Insert( Node *node, int value ){
    
        if( node == NULL )
            return new Node(value);
        
        if( node -> left != NULL )
            Insert( node -> left, value );
        else 
            node -> left = Insert( node -> left, value );
        
        if( node -> right != NULL )
            Insert( node -> right, value );
        else
            node -> right = Insert( node -> right, value );
        
        return node;
    }
    
    void Inorder(){
        Inorder( root );
    }

    void Inorder( Node *node ){
        if( node == NULL)
            return;

        Inorder( node -> left );
        cout << node -> value << endl;
        Inorder( node -> right );
    }
};

int main(){
    BinaryTree BT;
    BT.Insert( 1 );
    BT.Insert( 2 );
    BT.Insert( 3 );
    BT.Insert( 4 );
    BT.Insert( 5 );
    BT.Insert( 6 );
    BT.Inorder();
}