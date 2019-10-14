#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  cin.tie(nullptr);
  cout.tie(nullptr);

  auto s = string{};
  cin >> s;
  
  char c = s[ s.size() - 1 ];

  s[s.size() - 1] = 'i';

  s += "c";
  s += c;

  cout << s << endl;

  return 0;
}