//https://leetcode.com/problems/find-pivot-index/solution/
class Solution {
public:
    //Time O(n)
    //Memory O(m)
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        int max_sum;
        
        if(size == 0)
            return -1;
        
        vector<int> prefix_sum(size + 2, 0);
        
        for(int i = 0, j = 1; i < size; i++, j++)
            prefix_sum[j] = nums[i] + prefix_sum[j - 1];
        
        max_sum = prefix_sum[size];
        
        for(int i = 1; i <= size; i++) {
            const int left = prefix_sum[i - 1];
            const int right = max_sum - prefix_sum[i];
            if(left == right)
                return i - 1;
        }
            
        return -1;
    }

    //Time O(n)
    //Memory O(1)
    int pivotIndex(vector<int> &nums) {
        int left_sum = 0, right_sum = 0;
        int size = nums.size();

        for(const int num : nums)
            right_sum += num;
        
        for(int i = 0; i < size; i++){
            const int num = nums[i];
            if(left_sum == right_sum - left_sum - num)
                return i;
            left_sum += num;    
        }

        return -1;
    }
    
};