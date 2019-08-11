#include <bits/stdc++.h>

using namespace std;

using number = int64_t;
using m = map<pair<number, number>, number>;
auto lon(int i, number last, const vector<number> &data, m &dp) -> number {
  number A, B;
  pair<number, number> pos = {i, last};

  if (i >= data.size())
    return 0;
  if (dp.count(pos) != 0)
    return dp[pos];

  B = lon(i + 1, last, data, dp);

  if (last < data[i]) {

    A = 1 + lon(i + 1, data[i], data, dp);
    return dp[pos] = max(A, B);
  }
  return dp[pos] = B;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  auto data = vector<number>{1, 2, 5, 3, 4};
  m dp;
  cout << (data.size() - lon(0, INT64_MIN, data, dp)) << endl;

  cout << dp.size() << endl;
  return 0;
}