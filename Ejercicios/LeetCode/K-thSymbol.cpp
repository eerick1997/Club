//To prove this code send it in: https://leetcode.com/problems/k-th-symbol-in-grammar/
class Solution{
public:
    int kthGrammar(int N, int K){
        int n = K - 1, i = 0;
        //Counting the number of bits on
        for( ; n != 0; n >>= 1 )
            if( (n & 1) == 1 )
                i++;
        
        return i % 2;
    }
};

/**
If you know the bitset data type you just can made the next
int kthGrammar(int N, int K){
    bitset< 64 > ans( K - 1 );
    return ans.count() % 2;
}
**/