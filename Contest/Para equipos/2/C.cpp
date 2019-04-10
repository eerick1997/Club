#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

map<string, int> X;

lli f(lli A, lli B, lli C, lli x_i){
    return (( (A * x_i) + x_i % B) % C);
}

int main(){

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    lli A, B, C, i;
    fin >> A >> B >> C;
     
    lli a = 1, b = 1;
    X[to_string(a)]++;

    for(i = 1; X[to_string(b)] < 2 ; i++){
        a = f(A, B, C, b);
        X[to_string(a)]++;
        b = a;
    }

    if(i <= (20000000))
        fout<< (i - 1) << endl;
    else
        fout<< -1 << endl;

    return 0;
}