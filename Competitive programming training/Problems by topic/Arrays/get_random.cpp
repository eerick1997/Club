#include<bits/stdc++.h>

using namespace std;

int getRandom(vector<vector<int>> &ranges) {
    int numberOfElements = 0;
    int randomNumber = 0;
    int answer = 0;

    for(vector<int> range : ranges)
        numberOfElements += range[1] - range[0] + 1;
    
    srand(time(nullptr));
    randomNumber = rand() % numberOfElements;
    cout << "number of elements = " << numberOfElements << endl;
    cout << "randomNumber = " << randomNumber << endl;

    for(vector<int> &range : ranges) {
        const int currentNumberOfElements = range[1] - range[0] + 1;
        if(randomNumber < currentNumberOfElements) {
            answer = range[0] + randomNumber;
            break;
        } else
            randomNumber -= currentNumberOfElements;
    }
    return answer;
}

int main() {
    
    //  0, 1, 2, 3,4,5,6,7,8, 9,10,11
    //[12,13,14,15,1,2,3,4,5,32,33,34]
    vector<vector<int>> ranges = {{12,15},{1,5},{32,34}};
    int randomElement = getRandom(ranges);
    cout << "random element = " << randomElement << endl;
    return 0;
}