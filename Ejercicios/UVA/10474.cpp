/**Where is the marble**/

/**
    Constraints:
    1 <= N <= 1000
    Program ends if N and Q are equal to zero
 **/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //Inputs N = elements, Q = queries
    int N , Q;
    int i = 1;
    
    while(cin>>N>>Q && N != 0 && Q != 0){

        //Other variables
        vector<int> marble; 
        int end = N;
        //Reading all the marbles
        while(N--){
            int m = 0;
            cin>>m;
            marble.push_back(m);
        }
       
       //Ordering our vector
        sort(marble.begin(), marble.end());
            
       //We made each query
        cout<<"CASE# "<<i++<<":\n";
        
        while(Q--){
            int res = -1, mid = 0, ini = 0, end = 0;
            int val = 0;
            cin>>val;
            
            end = marble.size() - 1;
            
            //Binary search
            while(ini <= end){
                mid = (ini + end)/2;
                if(marble[mid] < val){
                    ini = mid + 1;
                } else {   
                    end = mid - 1;
                    res = mid;
                }
            }
            if(marble[res] == val)
                cout<<val<<" found at "<<res+1<<"\n";
            else
                cout<<val<<" not found\n";
        }
    }
    return 0;
}

