#include <bits/stdc++.h>

using namespace std;

struct candy{
    int left;
    int right;
    candy(){
        left = right = 1;
    }
};

int solve(vector<int> students) {
    vector<candy> candies(students.size(), candy());
    int answer = 0;

    //Solve subproblem to left to right
    for(int i = 1; i < students.size(); i++)
        if(students[i] > students[i - 1])
            candies[ i ].left = candies[i - 1].left + 1;
    
    //Solve subproblem to right to left
    for(int i = students.size() - 2; i >= 0; i--)
        if(students[i] > students[i + 1])
            candies[i].right = candies[i + 1].right + 1;
    
    for(const candy C : candies)
        answer += max(C.left, C.right);

    return answer;
}

int main() {
    int n_students;
    vector<int> student;
    cin >> n_students;
    student.resize(n_students);

    for(int i = 0; i < n_students; i++)
        cin >> student[i];
    
    cout << solve(student) << endl;
    
    return 0;
}