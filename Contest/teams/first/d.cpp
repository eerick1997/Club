#include <bits/stdc++.h>

using namespace std;

int distance(pair<int, int> start, pair<int, int> target){
    return (int)( sqrt( pow(start.first - target.first, 2) + pow(start.second - target.second, 2) ) );
}

int main(){
    int N;
    int d;
    pair<int, int> start, target;
    cin >> N >> start.first >> start.second >> target.first >> target.second;
    d = distance(start, target);
    cout << d << endl;
    if(d == N){
        cout << "d == N" << endl;
        cout << (d) << endl;
    } else if(d > N) {
        cout << 0 << endl;
    } else {
        cout << abs( N - (d / 2) ) << endl;
    }
    return 0;
}