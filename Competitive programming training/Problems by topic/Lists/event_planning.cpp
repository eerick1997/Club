#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

const lli MAX = 1e15;

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli participants, budget, hotels, weeks, price_per_person, beds_week_i;
    lli max_beds_week_i = -MAX, ans = MAX, current_price;
    while( cin >> participants >> budget >> hotels >> weeks and participants and budget and hotels and weeks ) {
        ans = MAX;

        for( int i = 0; i < hotels; i++ ) {

            max_beds_week_i = -MAX;

            cin >> price_per_person;

            current_price = price_per_person * participants;
            
            for( int j = 0; j < weeks; j++ ) {
                cin >> beds_week_i;
                max_beds_week_i = max( max_beds_week_i, beds_week_i );
            }
            if( max_beds_week_i >= participants )
                if( current_price <= budget )
                    ans = min( ans, current_price );

        }

        if( ans == MAX )
            cout << "stay home" << endl;
        else 
            cout << ans << endl;
    }
}