#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

int main() {
    int lengthBase, numberOfBlocks, ans = INT_MIN;
    int horizontalLength, verticalLength, beginPoint;
    vector<int> box;
    cin >> lengthBase >> numberOfBlocks;
    box.resize(lengthBase, 0);

    for(int i = 0; i < numberOfBlocks; i++) {
        cin >> horizontalLength >> verticalLength >> beginPoint;
        box[beginPoint] += verticalLength; 
        for(int j = beginPoint; j <= beginPoint + horizontalLength - 1; j++) {
            box[beginPoint] = box[beginPoint]
        }
    }

    for(const int height : box)
        cout << height << " ";
    cout << endl;
    /*for(const int height : box)
        ans = max(ans, height);    
    cout << ans << endl; */
}