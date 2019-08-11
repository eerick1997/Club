#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, v;
  vector<int> days;
  cin >> n;
  while (n--) {
    cin >> v;
    days.push_back(v);
  }

  int start, end, current = 0;
  int box = 0;
  while (current < days.size()) {
    int last = current;

    while (days[last] <= days[current] + 20 && last < days.size()) {
      last++;
    }
    last--;

    int dist = 0;
    for (auto i = current; i < last; ++i) {
      dist += (days[last] - days[i]);
    }
        dist -= 20;
    while (dist >= 20 && (last > current)) {
      last--;
      dist -= (last - current) * (days[last + 1] - days[last]);
      cout << dist << endl;
    }

    //cout << current << " " << last << endl;
    current = last + 1;
    box++;
  }

  cout << box << endl;

  return 0;
}