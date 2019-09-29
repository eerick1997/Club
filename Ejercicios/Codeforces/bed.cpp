#include <bits/stdc++.h>
#define PI acos( -1 )

using namespace std;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    double lengthBed, widthBed, aniasHeight, x, y, angle, angleR;
    double error = 0, X, Y;
    cin >> lengthBed >> widthBed >> aniasHeight >> x >> y >> angle;

    error = 0.001 ;

    angleR = angle*PI / 180.00;

    X = x + aniasHeight * cos( angleR );    
    Y = y + aniasHeight * sin( angleR );

    if( X > ( widthBed + error ) || Y > ( lengthBed + error ) || X < -error || Y < -error )
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;

    

    return 0;
}