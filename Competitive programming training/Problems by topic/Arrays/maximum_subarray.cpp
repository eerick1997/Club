class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        int current_sum = nums[0];
        int ans = nums[0];
        for(int i = 1; i < size; i++) {
            const int num = nums[i];
            current_sum = max(num, current_sum + num);
            ans = max(ans, current_sum);
        }
        return ans;
    }
};