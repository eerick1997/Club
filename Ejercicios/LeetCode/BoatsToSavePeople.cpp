//Link: https://leetcode.com/problems/boats-to-save-people
//Time complexity: O( n )
//Space complexity: O( 1 )
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        sort( people.begin(), people.end() );
        
        while( left <= right ){
            boats++;
            if( people[ left ] + people[ right ] <= limit )
                left++;
            right--;
        }
        return boats;
    }
    
};