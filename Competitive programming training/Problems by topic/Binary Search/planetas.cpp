#include <bits/stdc++.h>

using namespace std;

vector<double> planets;

double check(double M) {
    double ans = 0;
    for(double planet : planets)
        ans += 1 / (planet - M);
    return ans;
}

double binary_search(double begin, double end) {
    double lenght = 0, ans = 0;
    for(int i = 0; i < 27; i++) {
        lenght = begin + ((end - begin) / 2);
        if(check(lenght) >= 0)
            end = ans = lenght;
        else 
            begin = lenght;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cout << fixed << setprecision(3);
    int n_planets;
    int begin, end, lenght;
    cin >> n_planets;
    planets.resize(n_planets);

    for(int i = 0; i < n_planets; i++)
        cin >> planets[i];

    sort(planets.begin(), planets.end());

    cout << n_planets - 1 << endl;
    for(int i = 0; i < n_planets - 1; i++) {
        begin = planets[i], end = planets[i + 1];
        cout << binary_search(begin, end) << " ";
    }
    return 0;
}