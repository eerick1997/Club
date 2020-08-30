//https://leetcode.com/problems/house-robber/
class Solution {
public:
    
    int getMaximumMoney(int index, vector<int> &money, vector<int> &DP) {
        if(index >= money.size())
            return 0;
        
        if(DP[index] != -1)
            return DP[index];
        
        int rob_current = getMaximumMoney(index + 2, money, DP) + money[index];
        int not_robe = getMaximumMoney(index + 1, money, DP);
        
        return DP[index] = max(rob_current, not_robe);
    }
    
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> DP(size, -1);
        return getMaximumMoney(0, nums, DP);
    }
};