//https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> opposite;
        int ans = 0;
        
        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == k)
                ans++;
            ans += opposite[nums[i]];
            opposite[k + nums[i]]++;
        }

        return ans;
    }
};