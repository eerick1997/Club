//https://leetcode.com/problems/subarray-sums-divisible-by-k/
class Solution {
public:
    
    int mod(int a, int k) {
        return ((a % k) + k) % k;
    } 
    
    int subarraysDivByK(vector<int>& A, int K) {
        int size = A.size(), ans = 0;
        unordered_map<int, int> complement;
        
        for(int i = 1; i < size; i++)
            A[i] += A[i - 1];
        
        for(int i = 0; i < size; i++) {
            const int current = mod(A[i], K);
            if(current == 0)
                ans++;
            ans += complement[current];
            complement[current]++;
        }
        
        return ans;
    }
};