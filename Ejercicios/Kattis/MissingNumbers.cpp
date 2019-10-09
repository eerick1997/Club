#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {

  int n;
  cin >> n;
  vector<int> num;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    num.push_back(x);
  }

  int maxi = num[num.size() - 1];

  vector<int> buck(maxi + 1, 0);

  for (int i = 0; i < n; i++) {
    buck[num[i]]++;
  }

  vector<int> res;
  for (int i = 1; i <= maxi; i++) {
    if (buck[i] == 0)
      res.push_back(i);
  }

  if (res.size() == 0) {
    cout << "good job\n";
  } else {
    for (int i : res)
      cout << i << "\n";
  }

  return 0;
}