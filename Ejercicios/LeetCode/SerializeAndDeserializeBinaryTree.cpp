//link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
//Time complexity O(n) to serialize and deserialize
//Space complexity O(n) to serialize and deserialize
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //The current node is null? if yes, return X
        if( !root )
            return "X,";
        
        string center = to_string(root -> val) + ",";
        string left = serialize( root -> left );
        string right = serialize( root -> right );
        return (center + left + right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        //First we need to get our tokens
        queue< string > tokens;
        string aux = "";
        //We split the tokens
        for( char c : data ){
            if( c == ',' ){
                tokens.push( aux );
                aux = "";
            } else {
                aux += c;
            }
        }
        
        return helper( tokens );
    }
    
    TreeNode *helper( queue< string > &tokens ){
        if( tokens.empty() )
            return NULL;
        
        string value = tokens.front();
        tokens.pop();
        if( value == "X" )
            return NULL;
        
        TreeNode *root = new TreeNode( stoi( value ) );
        root -> left = helper( tokens );
        root -> right = helper( tokens );
        return root;
    }   
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));