#include <complex>
#include <iostream>
#include <map>
#include <string>

using namespace std;

auto main() -> int {

  const auto i = complex<int>{0, 1};
  auto steps = map<string, complex<int>>{{"left", i}, {"right", -i}};

  auto cases = 0;
  cin >> cases;
  auto start = i;
  auto data = string{};

  while (cases--) {
    cin >> data;

    if (data == "back")
      start *= -1;
    else
      start *= steps[data];
  }

  if (start == i)
    cout << "north" << endl;
  else if (start == -i)
    cout << "south" << endl;
  else if (start == 1)
    cout << "east" << endl;
  else if (start == -1)
    cout << "west" << endl;

  return 0;
}