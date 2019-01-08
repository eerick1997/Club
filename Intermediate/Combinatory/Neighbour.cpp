#include <bits/stdc++.h>

using namspace std;

int x = 0;
int n = 0;
int arr[10];
int y = 1000000;

int main(){
    cin>>x;
    int cx = x;
    while(cx > 0){
        arr[n] = cx % 10;
        cx /= 10;
        n++;
    }
    sort(arr, arr+n);
    while(next_permutation(arr, arr+n)){
        int pY = pDiez = 1;
        for(int i = n-1; i>= 0; i--){
            pY += arr[i]*pDiez;
            pDiez *= 10;
        }
        if(pY > x){
            y = min(y, pY);
        }
    }
    if(y != 1000000)
        cout<<y<<endl;
    else 
        cout<<"0"<<endl;
    return 0;
}
