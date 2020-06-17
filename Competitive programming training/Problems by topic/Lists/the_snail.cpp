#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    float height, distance_with_sun, distance_without_sun, fatigue, current_height;
    int day;
    while( cin >> height >> distance_with_sun >> distance_without_sun >> fatigue and height ) {
        fatigue = (fatigue / 100) * distance_with_sun;
        current_height = day = 0;
        while( true ){
            day++;

            if( distance_with_sun >= 0)
                current_height += distance_with_sun;
                
            if( current_height > height )
                break;

            current_height -= distance_without_sun;

            if( current_height < 0 )
                break;
            
            distance_with_sun -= fatigue;

        }
        cout << ( current_height < 0 ? "failure " : "success ") << "on day " << day << endl;
    }
    return 0;
}