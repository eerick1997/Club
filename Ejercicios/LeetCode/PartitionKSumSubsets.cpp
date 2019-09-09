//To prove this code just send it here: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
class Solution{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k){
        int sum = 0;
        //We get the sum of all the elements of nums vector
        for( auto e : nums )
            sum += e;
        //If k <= 0 we can not divide the nums vector in subsets so we return false
        /* To know the value of each subset we need to use sum mod k if the result is equal to zero 
           it means that we can use all the elements of the array just once */
        if( k <= 0 || sum % k != 0 )
            return false; //We can not divide in subsets the array or we can not find a valid solution
        //To know if we can use the i-th element we need to know if we already visited it like a graph
        vector<bool> visited( nums.size(), false );
        return canDivide( nums, k, 0, 0, sum / k, visited );
    }

    bool canDivide( vector<int> &nums, int k, int i, int currentSum, int target, vector<bool> &visited){
        //If k == 1 the sum of the rest elements have to sum the target so the answer is true 
        if( k == 1 )
            return true;
        //If the current sum and the target are equal we need to find the subset that sums the target
        //if we find a valid subset we return true, false otherwise
        if( currentSum == target)
            return canDivide( nums, k - 1, 0, 0, target, visited );
        
        //We try to find a valid subset from the i-th element to the n-th element
        for( int j = i; j < nums.size(); j++ ){
            //But we need to use just unvisited elements
            if( !visited[j] ){
                //We try with the current element
                visited[j] = true;
                //If we find a valid subset we return true
                if( canDivide( nums, k, j + 1, currentSum + nums[j], target, visited ) )
                    return true;
                //If we do not get a valid subset we can use in other subset the current element
                visited[j] = false;
            }
        }
        //We do not find a valid subset
        return false;
    }
};