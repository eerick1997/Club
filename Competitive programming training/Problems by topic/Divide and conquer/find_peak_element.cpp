//https://leetcode.com/problems/find-peak-element/submissions/
class Solution {
public:
    
    bool isPeak(vector<int> &nums, int index) {
        const int size = nums.size();
        return (index == 0 or nums[index] > nums[index - 1]) and (index == size - 1 or nums[index] > nums[index + 1]);
    }
    
    int splitNums(vector<int> &nums, int low, int high) {
        const int middle = ((high + low) >> 1);
        
        if(low <= high) {
            if(isPeak(nums, middle))
                return middle;

            int left = splitNums(nums, low, middle - 1);
            if(left != -1)
                return left;

            int right = splitNums(nums, middle + 1, high);
            if(right != -1)
                return right;
        }
        return -1;
    }
    
    int findPeakElement(vector<int>& nums) {
        const int size = nums.size();
        return splitNums(nums, 0, size - 1);
    }
};