//https://leetcode.com/problems/n-th-tribonacci-number/
class Solution {
public:
    //With constant memory and O(n) time, but also can do it with O(n) memory and time
    int tribonacci(int n) {
        int Tn3;
        int Tn2 = 1, Tn1 = 1, Tn = 0;
        if(n == 0)
            return 0;
        if(n <= 2)
            return 1;
        
        for(int i = 0; i <= n - 3; i++) {
            Tn3 = Tn + Tn1 + Tn2;
            Tn = Tn1;
            Tn1 = Tn2;
            Tn2 = Tn3;
        }
        return Tn3;
    }
};