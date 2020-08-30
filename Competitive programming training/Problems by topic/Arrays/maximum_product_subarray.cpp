//https://leetcode.com/problems/maximum-product-subarray
class Solution {
public:
    /*
    Consider that we can have 3 cases
    1. Current element is positive so we need to multiply the current element with the maximum at this point
    2. Current element is negative so we need to multiply the current element with the minimum at this point
    3. Current element is the maximum
    */
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int current_max_product = nums[0];
        int current_min_product = nums[0];
        int prev_max_product = nums[0];
        int prev_min_product = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            const int num = nums[i];
            //Here we evaluate the cases described above
            current_max_product = max({num, prev_max_product * num, prev_min_product * num});
            current_min_product = min({num, prev_max_product * num, prev_min_product * num});
            ans = max(current_max_product, ans);
            prev_max_product = current_max_product;
            prev_min_product = current_min_product;
        }
        
        return ans;
    }
};