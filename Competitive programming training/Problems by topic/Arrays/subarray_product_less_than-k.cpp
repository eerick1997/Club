//https://leetcode.com/problems/subarray-product-less-than-k/submissions/
//Sliding window technique

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        int ans = 0;
        int current_value = 1;
        
        if(k <= 1) return 0;
        
        for(int left = 0, right = 0; right < size; right++) {
            current_value *= nums[right];
            while(current_value >= k) {
                current_value /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        
        return ans;
    }
};