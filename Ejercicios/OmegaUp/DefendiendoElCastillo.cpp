#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
vector<lli> a(1500002, 0);
vector<lli> aux(1500002, 0);

bool validate(lli middle, lli n, lli r, lli k){
    
    bool ans = true;
    lli count = 0;

    //First case
    for(int i = 1 + n - r; i <= 1 + n + r; i++)
        count += a[i];

    if(count < middle){
        lli need = middle - count;
        if(need <= k){
            count += need;
            aux[1 + n + r] += need;
            k -= need;
        } else {
            ans = false;
        }
    }

    //The rest cases
    if(ans){
        for(int i = 2 + n; i <= 2 * n; i++){
            count -= a[i - r - 1] + aux[i - r - 1];
            aux[i - r - 1] = 0;
            count += a[i + r];

            if(count < middle){
                lli need = middle - count;
                if(need <= k){
                    count += need;
                    aux[i + r] += need;
                    k -= need;
                } else {
                    ans = false;
                }
            }
        }
    }   
    return ans;
}

int main(){
    lli n, r, k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r >> k;

    for(int i = 1; i <= n; i++)
        cin >> a[i + n];
    
    lli begin = 0, end = LLONG_MAX, middle = 0, ans = -1;

    while(begin <= end){
        middle = (begin + end) >> 1;

        if(validate(middle, n, r, k)){  
            ans = middle;
            begin = middle + 1;
        } else {
            end = middle - 1;
        }

    }

    cout << ans << endl;

    return 0;
}