void generate(int i, int limit, int left, int right, vector<string> &ans){
    static char str[256];

    if(right == limit){
        ans.push_back(str);
    } else {

        if(left > right){
            str[i] = ')';
            generate(i + 1, limit, left, right + 1, ans);
        } 
        
        if(left < limit) {
            str[i] = '(';
            generate(i + 1, limit, left + 1, right, ans);
        }
    }
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    generate(0, A, 0, 0, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}
