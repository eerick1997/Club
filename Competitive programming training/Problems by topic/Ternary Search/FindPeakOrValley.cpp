#include <bits/stdc++.h>

using namespace std;

bool isPeakOrValley(vector<int> &nums, int i) {
    return (nums[i] > nums[i + 1] and nums[i] > nums[i - 1]) or (nums[i] < nums[i + 1] and nums[i] < nums[i - 1]);
}

int findPeakOrValley(vector<int> &nums) {
    int low, high, middle1, middle2;
    low = 0, high = nums.size() - 1;
    while(low <= high) {
        middle1 = low + (high - low) / 3;
        middle2 = high - (high - low) / 3;
        if(isPeakOrValley(nums, middle1))
            return middle1;
        
        if(isPeakOrValley(nums, middle2))
            return middle2;

        if(nums[middle1] == nums[middle2]) 
            low = middle1 + 1, high = middle2 - 1;
        else if(nums[middle1] > nums[middle2])
            high = middle2 - 1;
        else //nums[middle2] > nums[middle1] 
            low = middle1 + 1;
    }
    return -1;
}

int main() {
    int nNumbers;
    vector<int> nums;
    cin >> nNumbers;
    nums.resize(nNumbers);
    for(int &num: nums)
        cin >> num;

    cout << findPeakOrValley(nums) << endl;
}