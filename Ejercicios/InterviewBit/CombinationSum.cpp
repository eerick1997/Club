//Link: https://www.interviewbit.com/problems/combination-sum-ii/#
//Time complexity: O( n^{n} )
//Space complexity: O( n^{n} )


void getAllCombinations( vector< int > &A, vector< bool > &visited, int index, int target, int sum, vector< int > subset, set< vector<int > > &subsets ){
    
    if( target == sum ){
        subsets.insert( subset );
        return;
    }
    
    if( sum > target )
        return;
    
    if( index == A.size() )
        return;
        
    for( int i = index; i < A.size(); i++ ){
        if( !visited[ i ] ){
            visited[ i ] = true;
            if( sum + A[ i ] <= target ){
                subset.push_back( A[ i ] );
                getAllCombinations(A, visited, i + 1, target, sum + A[ i ], subset, subsets);
            }
            subset.pop_back();
            visited[ i ] = false;
        }
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector< vector< int > > ans;
    set< vector<int> > subsets;
    sort( A.begin(), A.end() );
    vector< bool > visited( A.size(), false );
    getAllCombinations( A, visited, 0, B, 0, {}, subsets );
    for( auto subset : subsets )
        ans.push_back( subset );
    
    return ans;
}