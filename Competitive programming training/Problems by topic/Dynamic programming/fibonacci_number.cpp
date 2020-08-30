//https://leetcode.com/problems/fibonacci-number/submissions/
class Solution {
public:
    int fib(int N) {
        vector<int> fibonacci(N + 2, 0);
        fibonacci[1] = 1;
        
        for(int i = 2; i <= N; i++)
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        
        return fibonacci[N];
    }
};