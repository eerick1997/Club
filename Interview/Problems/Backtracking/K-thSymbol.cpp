//To prove this code send it in: https://leetcode.com/problems/k-th-symbol-in-grammar/
/* Check the next pattern
Number        n - 1       binary      bits on    bits on % 2
    #1          0           0           0           0
    #2          1           1           1           1
    #3          2           10          1           1
    #4          3           11          2           0
    #5          4           100         1           1
    #6          5           101         2           0
    #7          6           110         2           0
    #8          7           111         3           1
 */
class Solution{
public:
    int kthGrammar(int N, int K){
        int n = K - 1, i = 0;
        //Counting the number of bits on
        for( ; n != 0; n >>= 1 )
            //If we find a bit on ( XXXXX1 & 000001 = 1 = true)
            if( (n & 1) == 1 )
                //We count a new one
                i++;
        
        //The K-th element
        return i % 2;
    }
};