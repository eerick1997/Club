#include <bits/stdc++.h>
using namespace std;


using number = unsigned long long int;
using powers = array<number, 9>;

void print(powers& p) {
    for (auto x : p) {
        cout << x << ", ";
    }
    cout << endl << endl;
}

powers primes {2, 3, 5, 7, 11, 13, 17, 23, 29};

int main () {
    number n;
    cin >> n;

    vector<powers>numbers(n + 1);

    powers generalSum {};
    for(int j = 0; j < n; j++) {
        number theNumber;
        cin >> theNumber;

        powers p {};
        for(int i = 0; i < 9; i++) {
            number power {};
            number prime = primes[i];
            while(theNumber % prime == 0) {
                theNumber /= prime;
                power++;
            }
            p[i] = power;
            generalSum[i] += power;
        }

        numbers[j] = p;
    }

    

    powers initialSum {generalSum};
    for(number sizeMax = n; true; sizeMax--) {
        for(int j = 0; j < 9; j++) initialSum[j] -= numbers[sizeMax][j];
        powers sum {initialSum};
        
        auto moves = (n - ssizeMax) + 1;

        for(number i = 0; i < moves; i++) {
            
            bool isGood = true;
            for(int j = 0; j < 9 && isGood; j++) isGood = sum[j] % 2 == 0;
            if (isGood) {
                cout << sizeMax << endl;
                exit(0);
            }

            if (n - sizeMax == 0) break; 

            for (int j = 0; j < 9; j++) sum[j] -= numbers[i][j];
            for (int j = 0; j < 9; j++) sum[j] += numbers[sizeMax + i][j];
        }
    }
    


    number sizeOfTheThing {n};
    while (true) {
        bool reset = false;
        int i;
        for(i = 0; i < 9 && !reset; i++) {
            if (generalSum[i] % 2 == 0) continue;

            for (auto& power : numbers) {
                if (generalSum[i] - power[i] != 0) continue;

                for(int i = 0; i < 9; i++) generalSum[i] -= power[i];
                reset = true;
                sizeOfTheThing--;
            }
        }

        if (i == 9) break;
    }

    cout << sizeOfTheThing << endl;
   

    return 0;
}