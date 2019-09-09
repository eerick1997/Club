//Problem link: https://leetcode.com/problems/permutations/
//Time complexity O(n * n!)
//Space complexity O( n * n! )
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > ans;
        vector< bool > visited( nums.size(), false );
        vector< int > current;
        makePermutation( nums, visited, current, ans );
        return ans;
    }
    
    void makePermutation( vector<int> &nums, vector<bool> &visited, vector< int > current, vector< vector< int > > &ans){
        
        if( current.size() == nums.size() ){
            ans.push_back( current );
            return;
        }
        
        for( int i = 0; i < nums.size(); i++ ){
            if( !visited[ i ] ){
                visited[ i ] = true;
                current.push_back( nums[ i ] );
                makePermutation( nums, visited, current, ans );
                current.pop_back();
                visited[ i ] = false;
            }
        }
            
    }
};