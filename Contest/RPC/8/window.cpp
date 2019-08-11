#include <bits/stdc++.h>
using namespace std;


auto main () -> int {

    int64_t weight, height, gap;

    cin >> weight >> height >> gap;

    auto result = (weight - 2 * gap)*(height - 2 * gap);
    cout << max(0l, result) << endl;

    return 0;
}