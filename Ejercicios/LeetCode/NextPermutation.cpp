#include <bits/stdc++.h>

using namespace std;

//Problem: https://leetcode.com/problems/next-permutation/#
//Time complexity: 
//Space complexity:

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int current, last;
        for( current = 1, last = 0; current < nums.size(); current++, last++ )
            if( nums[ last ] < nums[ current ] )
                break;
        
        while( nums[ current ] > nums[ last ] )
            current++;

        swap( nums[ current ], nums[ last ] );
        
        reverse( nums.begin() + current, nums.end() );
        
        for( int e : nums )
            cout << e << " ";
        cout << endl;
    }
};

int main(){
    int n;
    vector< int > nums;
    Solution solution;
    cin >> n;
    nums.assign( n, 0 );
    for( int i = 0; i < n; i++ )
        cin >> nums[ i ];
    
    solution.nextPermutation( nums );

    return 0;
}