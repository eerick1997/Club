#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
  
int main (){
    
    int T;
    cin>>T;
    while(T--){
        ll n, mod;
        //cin>>n>>mod;
        scanf("%lld %lld", &n, &mod);
        vector<ll>nums;
        for(int i = 0; i < n; i++){
            ll x;
            scanf("%lld", &x);
            nums.push_back(x);
        }
        
        if(nums[0] != -1){ //Formula desde el primero hasta el ultimo elemento 
            for(int i = 1; i < nums.size(); i++){
               nums[i] = (nums[i-1] + 1) % mod;
            }
          
        }else if(nums[nums.size()-1] != -1){
            
            
            for(int i = nums.size()-2; i >= 0; i--){
                if(nums[i] == -1){
                    nums[i] = ((nums[i+1]-1) % mod + mod) % mod;
                }
            }
            
        }else{
            
            int idx;
            for(int i = nums.size()-1; i >= 0; i--){
                if(nums[i] != -1){
                    idx = i;
                    break;
                }
            }
            
            for(int i = idx+1; i < nums.size(); i++){
                    nums[i] = (nums[i-1] + 1) % mod;
            }
            
            for(int i = nums.size()-2; i >= 0; i--){
                nums[i] = ((nums[i+1]-1) % mod + mod) % mod;
                    
            }
            
        }
        
        
        for(int i = 0; i < nums.size(); i++)
            printf("%lld ", nums[i]);
        
        printf("\n");
    }
    
    
    
    
    return 0;
}
