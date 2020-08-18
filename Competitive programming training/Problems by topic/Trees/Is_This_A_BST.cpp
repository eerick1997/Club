/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

    void helper(Node *root, vector<Node*> &nodes) {
        if(root == nullptr)
            return;
        
        helper(root -> left);
        nodes.push_back(root);
        helper(root -> right);
    }

	bool checkBST(Node* root) {
		vector<Node*> nodes;
        helper(root, nodes);
        for(int i = 0; i < nodes.size() - 1; i++)
            if(nodes[i] >= nodes[i + 1])
                return false;
        return true;
	}