//https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    void traverseTree(TreeNode *root, vector<int> &values) {
        if(root == nullptr)
            return;
        
        traverseTree(root -> left, values);
        values.push_back(root -> val);
        traverseTree(root -> right, values);
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> values;
        int ans = INT32_MAX;
        
        traverseTree(root, values);
        
        for(int i = 0; i < values.size() - 1; i++)
            ans = min(ans, (values[i + 1] - values[i]));
        
        return ans;
    }
};