//https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    
    int isPeak(vector<int> &m, int index) {
        return m[index] > m[index + 1] and m[index] > m[index - 1];
    }
    
    //Time: O(log3(n))
    //Memory: O(1)
    int peakIndexInMountainArray(vector<int>& A) {
        int low = 0;
        int high = A.size() - 1;
        int m1, m2;
        while(low <= high) {
            m1 = low + ((high - low) / 3);
            m2 = high - ((high - low) / 3);
            if(isPeak(A, m1))
                return m1;
            if(isPeak(A, m2))
                return m2;
                
            if(A[m1] == A[m2])
                low = m1 + 1, high = m2 - 1;
            else if(A[m1] > A[m2])
                high = m2 - 1;
            else 
                low = m1 + 1;
                
        }
        return m1;
    }
    
    //Time: O(n)
    //Memory: O(1)
    int peakIndexInMountainArray(vector<int>& A) {
        int size = A.size();
        for(int i = 0; i < size - 1; i++) {
            const int current = A[i];
            const int next = A[i + 1];
            if(current > next)
                return i;
        }
        return 0;
    }
};