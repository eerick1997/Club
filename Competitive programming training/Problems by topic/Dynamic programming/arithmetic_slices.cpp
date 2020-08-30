class Solution {
public:
    
    int countGroups(int left, int right) {
        int n = right - left - 1;
        return (n * (n + 1)) / 2;
    }
    
    //Using DP and two pointers
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> differences;
        int size = A.size();
        int ans = 0, left, right;
        
        if(size == 0)
            return 0;
        
        differences.resize(size - 1);
        
        for(int i = 0; i < size - 1; i++)
            differences[i] = (A[i] - A[i + 1]);
        
        for(left = 0, right = 0; right < size - 1; right++) {
            if(differences[left] != differences[right])
                ans += countGroups(left, right), left = right;
        }
        
        ans += countGroups(left, right);
        
        return ans;
    }
    //Better solution without extra memory.
    int numberOfArithmeticSlices(vector<int> &A) {
        int size = A.size();
        int ans = 0, count = 0;
        if(size == 0)
            return 0;

        for(int i = 2; i < size; i++) {
            const int right = A[i] - A[i - 1];
            const int left = A[i - 1] - A[i - 2];
            if(left == right)
                count++;
            else 
                ans += countGroups(0, count + 1), count = 0;
        }

        return ans;
    }
};