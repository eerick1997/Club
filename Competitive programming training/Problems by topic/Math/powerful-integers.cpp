//https://leetcode.com/problems/powerful-integers/
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        unordered_set<int> already_calculated;
        
        for(int i = 1; i < bound; i *= x) {
            for(int j = 1; j < bound; j *= y) {
                if(i + j <= bound and already_calculated.count(i + j) == 0)
                    ans.push_back(i + j);
                
                already_calculated.insert(i + j);
                if(y == 1)
                    break;
            }
            if(x == 1)
                break;
        }
        
        return ans;
    }
};