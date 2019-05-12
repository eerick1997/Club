#include <bits/stdc++.h>
using namespace std;


using number = unsigned long long int;
int main () {

    number n;
    cin >> n;

    vector<number>numbers(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    number acumulado = numbers[0];

    if (acumulado != 1) {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1; i < n; i++) {
        if (numbers[i] - numbers[i - 1] < 2) {
            acumulado += numbers[i];
        }
        else {
            auto toGet = numbers[i] - 1;
            if (toGet > acumulado) {
                break;
            }
            else acumulado += numbers[i];
        }
    }

    cout << acumulado + 1 << endl;

    return 0;
}