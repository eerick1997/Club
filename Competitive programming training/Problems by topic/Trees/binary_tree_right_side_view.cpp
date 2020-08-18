//https://leetcode.com/problems/binary-tree-right-side-view/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        TreeNode *current_node;
        queue<TreeNode*> Queue;
        Queue.push(root);
        int n_nodes_next_level = 0, n_nodes_current_level = 1;
        if(root == nullptr)
            return {};
        
        while(!Queue.empty()) {
            current_node = Queue.front();
            Queue.pop();
            
            if(current_node -> left != nullptr)
                Queue.push(current_node -> left), n_nodes_next_level++;
            if(current_node -> right != nullptr)
                Queue.push(current_node -> right), n_nodes_next_level++;

            
            n_nodes_current_level--;
            
            if(n_nodes_current_level == 0) {
                ans.push_back(current_node -> val); 
                n_nodes_current_level = n_nodes_next_level;
                n_nodes_next_level = 0;
            }
        }
        
        return ans;
    }
};