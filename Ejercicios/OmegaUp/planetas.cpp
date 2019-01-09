#include <bits/stdc++.h>

using namespace std;

vector<int> planets;

double force(double M){
    double ans = 0;
    for(int i = 0; i < planets.size(); i++)
        ans += 1 / (planets[i] - M);
    return ans;
}

int main(){

    int N;
    cin >> N;
    while(N--){
        double p;
        cin >> p;
        planets.push_back(p);
    }

    sort(planets.begin(), planets.end());

    cout << (planets.size() - 1) << endl;
    for(int i = 1; i < planets.size(); i++){

        double begin = planets[i - 1];
        double end = planets[i];

        for(int j = 0; j < 25; j++){

            double M = (begin + end) / 2;
            double ans = force(M);
            if(ans > 0)
                end = M;
            else
                begin = M;
        }
        std::cout << std::fixed;
        std::cout << std::setprecision(3);
        cout << begin << " ";
    }

    return 0;
}