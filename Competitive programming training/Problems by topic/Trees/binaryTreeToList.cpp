#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

class BinaryTree{

public:
    Node *root;
    BinaryTree(int val) : root(new Node(val)) {}

    Node *buildList(Node *leftList, Node *rightList) {
        if(leftList == nullptr)
            return rightList;
        
        if(rightList == nullptr)
            return leftList;

        Node *tailLeft = leftList -> left;
        Node *tailRight = rightList -> left;

        tailLeft -> right = rightList;
        rightList -> left = tailLeft;

        leftList -> left = tailRight;
        tailRight -> right = leftList;

        return leftList;
    }

    Node *convertToList(Node *node) {
        if(node == nullptr)
            return nullptr;

        Node *leftSublist = convertToList(node -> left);
        Node *rightSublist = convertToList(node -> right);
        
        node -> left = node -> right = node;

        return buildList(buildList(leftSublist, node), rightSublist);
    }

    Node *convertToALinkedList() {
        if(root == nullptr)
            return nullptr;

        return convertToList(root);
    }

    void inorderTraversal() {
        if(root == nullptr)
            return;
        
        cout << "\n- Inorder traversal -\n";
        inorderTraversal(root);
        cout << "\n- - - - - - - - - - -\n";
    }

    void inorderTraversal(Node *node) {
        if(node == nullptr)
            return;
        
        inorderTraversal(node -> left);
        cout << node -> val << " ";
        inorderTraversal(node -> right);
    }
};

void printCircularLinkedList(Node *head) {
    Node *curr = head;
    cout << "\n- Circular linked list -\n";
    do {
        cout << curr -> val << " ";
        curr = curr -> right;
    } while(curr != head);
    cout << "\n- - - - - - - - - - - -\n";
}

int main() {
    BinaryTree *bt = new BinaryTree(1);
    bt -> root -> left = new Node(2);
    bt -> root -> left -> left = new Node(4);
    bt -> root -> left -> right = new Node(5);

    bt -> root -> right = new Node(3);
    bt -> root -> right -> left = new Node(6);
    bt -> root -> right -> right = new Node(7);

    bt -> inorderTraversal();

    printCircularLinkedList(bt -> convertToALinkedList());

}