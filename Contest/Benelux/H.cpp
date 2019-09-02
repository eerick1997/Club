#include <bits/stdc++.h>
using namespace std;
int main (){

    vector<pair<bool, bool>>movies(10e6+1);
    int n1, n2;
    int max1 = -1;
    int min1 = 1e9;
    //int min = 1e9
    int x;
    cin>>n1;
    for(int i = 0; i < n1; i++){
        cin>>x;
        movies[x].first = true;
        max1 = max(x, max1);
        min1 = min(x, min1);
        //min1 = min(x, min1);
    }
    cin>>n2;
    for(int i = 0; i < n2; i++){
        cin>>x;
        movies[x].second = true;
        max1 = max(x, max1);
        min1 = min(x, min1);
    }

    int cont = 0;
    int res = 0;
    //cout<<min1<<" y "<<max1<<endl;
    int ban = 0;
    for(int i = min1; i <= max1; i++){

        bool act1 = movies[i].first;
        bool act2 = movies[i].second;

        if(act1 && act2){cont++; ban = 0;}
        else if(act1 == false && ban == 1)ban = ban;
        else if(act2 == false && ban == 2)ban = ban;
        else if(act1 == true){
            cont++;
            ban = 2;
        }else if(act2 == true){
            cont++;
            ban = 1;
        }/* else {
            ban = 0;
        }*/

        //cout<<cont<<" y "<<ban<<"\n";

    }

    cout<<cont<<"\n";





    return 0; 
}