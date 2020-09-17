#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int _val) {
        val = _val;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int data) {
    if(root == nullptr or data == root -> val)
        return new Node(data);

    if(data > root -> val)
        root -> right = insert(root -> right, data);
    else
        root -> left = insert(root -> left, data);
    
    return root;
}

bool containsElement(Node *root, int key) {
    if(root == nullptr)
        return false;

    if(key == root -> val)
        return true;

    if(key > root -> val)
        return containsElement(root -> right, key);
    
    return containsElement(root -> left, key);
}

/**
It must print
[7, 8, 9, 10, 11, 12]
numbers in ascendent order!
**/
void inorderTraversal(Node *root) {
    if(root == nullptr)
        return;
    
    inorderTraversal(root -> left);
    cout << root -> val << " ";
    inorderTraversal(root -> right);

}

/**
            10
          /    \
         8     11
       /   \     \
      7    9     12
**/
int main() {
    Node *root = insert(root, 10);
    bool exist = false;
    insert(root, 8);
    insert(root, 7);
    insert(root, 9);
    insert(root, 11);
    insert(root, 12);
    inorderTraversal(root);
    cout << endl;
    exist = containsElement(root, 12);
    cout << "contains element 12? " << (exist ? "true" : "false") << endl;

    exist = containsElement(root, 7);
    cout << "contains element 7? " << (exist ? "true" : "false") << endl;

    exist = containsElement(root, 0);
    cout << "contains element 0? " << (exist ? "true" : "false") << endl;
    return 0;
}