#include <bits/stdc++.h>

using namespace std;
const double M_2PI = 2.0 * M_PI;

struct Punto{
    double x, y;
    
    Punto(){
        x = y = 0;
    }

    Punto(double X, double Y){
        x = X, y = Y;
    }

    Punto rotarD(const double& t) const{
        return Punto( x*cos(t) + y*sin(t), y*cos(t) - x*sin(t));
    }

    Punto rotarI(const double& t) const{
        return Punto( x*cos(t) - y*sin(t), y*cos(t) + x*sin(t));
    }

    int magnitud(){
        return round(sqrt( x*x + y*y ));
    }
};

double GradARad(double grd){
    return (grd * M_PI) / 180;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        Punto p;
        int C;
        cin >> C;
        while(C--){
            string command;
            int value;
            cin >> command >> value;
            if(command == "fd"){ // Move forward
                p.x += value;
            } else if(command == "lt"){ // Turn left
                p = p.rotarI( GradARad(value) );
            } else if(command == "bk"){ // Move backward
                p.x -= value;
            } else { //Turn right
                p = p.rotarD( GradARad(value) );
            }
        }
        cout << p.magnitud() << endl;
    }
    return 0;
}