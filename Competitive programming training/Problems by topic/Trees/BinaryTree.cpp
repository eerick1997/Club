#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int _data) {
        data = _data;
        left = right = nullptr;
    }
};

/* Using this traversal it must print
[2, 4, 1, 5, 3]
*/
void inorderTraversal(Node *root) {
    if(root == nullptr)
        return;
    
    inorderTraversal(root -> left);;
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

/*** Let's build the next tree
            5
        /       \
       4         3
     /   \     /   \
    2     1

***/
int main() {

    Node *root = new Node(5);
    root -> left = new Node(4);
    root -> left -> left = new Node(2);
    root -> left -> right = new Node(1);
    root -> right = new Node(3);
    inorderTraversal(root);
    return 0;
}