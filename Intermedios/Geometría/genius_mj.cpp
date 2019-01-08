#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

struct Punto{
    int x;
    int y;

    Punto(int X, int Y){
        x = X;
        y = Y;
    }

    Punto rot90() const {
        return Punto(-y, x);
    }

    bool operator==(const Punto& q) const{
        return (x == q.x) && (y == q.y);
    }
};

bool proof(vector< Punto >& p_m, vector< Punto >& p_h){

    bool match = true;
    for(int i = 0; i < p_m.size(); i++){
        if( !(p_m[i] == p_h[i]) ){
            p_m[i].rot90();
            match = false;  
        }
    }
    return match;
}

int main(){

    int T;
    cin >> T;
    while(T--){
        int N;
        bool match = false;
        vector< Punto > puerto_macho;
        vector< Punto > puerto_hembra;
        cin >> N;
        for(int i = 0, x = 0, y = 0; i < N; i++){
            cin >> x >> y;
            Punto pin(x, y);
            puerto_macho.push_back(pin);
        }

        for(int i = 0, x = 0, y = 0; i < N; i++){
            cin >> x >> y;
            Punto agujero(x, y);
            puerto_hembra.push_back(agujero);
        }

        for(int i = 0; i < 4 && !match; i++)
            match |= proof(puerto_macho, puerto_hembra);
        
        if(!match)
            cout << "NOT ";
        cout << "MATCHED" << endl;
    }
    return 0;
}