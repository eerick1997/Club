#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
double fillisMass, parachuteClosed, parachuteOpened, timeWhenParachuteIsOpened, height, queries;

const double G = 9.81;

bool check( double middle ){
    
}

int main(){

    cin >> fillisMass >> parachuteClosed >> parachuteOpened >> timeWhenParachuteIsOpened >> height >> queries;
    for( int i = 0, v; i < queries; i++ ){
        
        double begin = 0.0, middle = 0.0, end = 1 << 30;
        for( int j = 0; j < 30; j++ ){
            middle = (begin + end) / 2;
            if( check( middle ) ){
                begin = middle;
            } else {
                end = middle;
            }
        }
    }
}