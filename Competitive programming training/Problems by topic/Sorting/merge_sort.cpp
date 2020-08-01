#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &numbers, int left_1, int right_1, int right_2) {
    int left_2 = right_1 + 1;

    //Already sorted
    if(numbers[right_1] <= numbers[left_2])
        return;
    
    //Two pointers method
    while(left_1 <= right_1 and left_2 <= right_2) {
        if(numbers[left_1] <= numbers[left_2])
            left_1++;
        else {
            int current = numbers[left_2];
            int i = left_2;

            while(i != left_1) {
                numbers[i] = numbers[i - 1];
                i--;
            }

            numbers[left_1] = current;
            left_1++;
            right_1++;
            left_2++;
        }
    }
}

void merge_sort(vector<int> &numbers, int left, int right) {
    int middle = left + ((right - left) >> 1);
    //Just one element it is our base case
    if(left == right)
        return;
    //Split the vector in two parts from begin to middle
    merge_sort(numbers, left, middle);
    //Second part of the vector from the middle + 1 to the end
    merge_sort(numbers, middle + 1, right);
    //Take both parts of the subproblem and merge it
    merge(numbers, left, middle, right);
}

void print(vector<int> &numbers) {
    cout << endl;
    for(int number : numbers)
        cout << number << " ";
    cout << endl;
}

int main() {
    vector<int> numbers = {3, 5, 7, -1, 2, 100};
    int max_size = numbers.size() - 1;
    int min_size = 0;
    print(numbers);
    merge_sort(numbers, min_size, max_size);
    print(numbers);
    return 0;
}