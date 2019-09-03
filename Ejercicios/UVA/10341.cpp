#include <bits/stdc++.h>

using namespace std;
double p = 0, q = 0, r = 0, s = 0, t = 0, u = 0;
double evaluate( double middle ){
    double A = p * exp( -1 * middle );
    double B = q * sin( middle );
    double C = r * cos( middle );
    double D = s * tan( middle );
    double E = t * middle * middle;
    return (A + B + C + D + E + u);
}

int main(){
    
    while( cin >> p >> q >> r >> s >> t >> u ){
        double begin = 0, end = 1, middle = 0;
        for( int i = 0; i < 30; i++ ){
            middle = ( begin + end ) / 2;
            if( evaluate( middle ) > 0 )
                begin = middle;
            else
                end = middle;
        }
        int aux = evaluate(middle) * 10000;
        if( aux == 0){
            cout << fixed;
            cout << setprecision( 4 );
            cout << middle << endl;
        } else 
            cout << "No solution" << endl;

    }
}