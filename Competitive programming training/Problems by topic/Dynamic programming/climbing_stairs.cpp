//https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    
    int countWays(int n, vector<int> &DP) {
        if(n < 0)
            return 0;
        
        if(n == 0)
            return 1;
        
        if(DP[n] != -1)
            return DP[n];
        
        int move_one = countWays(n - 1, DP);
        int move_two = countWays(n - 2, DP);
        
        return DP[n] = move_one + move_two;
    }
    
    int climbStairs(int n) {
        vector<int> DP(n + 1, -1);
        
        return countWays(n, DP);
    }
};