//https://leetcode.com/problems/generate-parentheses/submissions/

class Solution {
public:
    
    void helper(int n_open, int n_close, string current, vector<string> &ans) {
        if(n_open == 0 and n_close == 0) {
            ans.push_back(current);
            return;
        }
        
        if(n_open > 0)
            helper(n_open - 1, n_close, current + "(", ans);
        
        if(n_close > n_open)
            helper(n_open, n_close - 1, current + ")", ans);            
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, n, "", ans);
        return ans;
    }
    
};