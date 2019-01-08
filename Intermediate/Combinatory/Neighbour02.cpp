#include <bits/stdc++.h>

using namespace std;

string x;

string y = "1000000";

int main(){
    cin>>x;
    if(next_permutation(x.begin(), x.end())){
        cout<<x;
    } else {
        cout<<"0"<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int x = 0;
int main(){
    cin>>x;
    cout<<((int)(log2(x)) + 1)<<endl;
    return 0;
}