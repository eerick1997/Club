#include <bits/stdc++.h>

using namespace std;

int main() {
    double duration, initial_payment, total, records, month, percentage, ans;
    while( cin >> duration >> initial_payment >> total >> records && duration >= 0 ) {
        for( int i = 0; i <= duration; i++ ) {
            cin >> month >> percentage;
            total += initial_payment;
        }

    }
    return 0;
}