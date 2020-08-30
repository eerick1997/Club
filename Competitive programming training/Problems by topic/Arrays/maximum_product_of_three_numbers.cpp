//https://leetcode.com/problems/maximum-product-of-three-numbers
class Solution {
public:
    
    int maximumProduct(vector<int>& nums) {
        int size = nums.size();
        int lastThree = INT32_MIN;
        int lastThreeWithNegatives = INT32_MIN;
        
        if(size < 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        lastThree = nums[size - 1] * nums[size - 2] * nums[size - 3];
        lastThreeWithNegatives = nums[size - 1] * nums[0] * nums[1];
        
        return max(lastThree, lastThreeWithNegatives);
    }
};