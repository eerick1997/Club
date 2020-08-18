#include <bits/stdc++.h>

using namespace std;

struct job{
    int start_time;
    int end_time;
    int profit;
    job() {}
};

bool compareJobs(const job a, const job b) {
    return a.start_time < b.start_time;
}

int solve(vector<job> &jobs, int current, int last) {
    if(current == jobs.size())
        return 0;

    //Overlaps?
    if(jobs[last].end_time < jobs[current].start_time)
        return 0;

    int take = solve(jobs, current + 1, current) + jobs[current].profit;
    int not_take = solve(jobs, current + 1, last);

    return max(take, not_take);
}

int max_profit(vector<job> &jobs) {
    sort(jobs.begin(), jobs.end(), compareJobs);
    return solve(jobs, 0, 0);
}

int main() {
    int n_jobs;
    vector<job> jobs;
    cin >> n_jobs;
    jobs.resize(n_jobs);
    for(int i = 0; i < n_jobs; i++)
        cin >> jobs[i].start_time >> jobs[i].end_time >> jobs[i].profit;
    
    cout << max_profit(jobs) << endl;
    return 0;
}