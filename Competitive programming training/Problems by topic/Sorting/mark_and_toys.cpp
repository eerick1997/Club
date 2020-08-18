#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

// Complete the maximumToys function below.
int maximumToys(vector<int> &prices, int k) {
    int n_toys = 0;
    sort(prices.begin(), prices.end());
    for(const int toy_price : prices) {
        if((k - toy_price) > 0)
            k -= toy_price, n_toys++;
    }
    return n_toys;
}

int main() {
    lli n_priced_toys, amount_to_spend;
    vector<lli> toys;

    cin >> n_priced_toys >> amount_to_spend;
    toys.resize(n_priced_toys);

    for(lli &toy : toys)
        cin >> toy;

    cout << maximumToys(toys, amount_to_spend) << endl;
    return 0;
}