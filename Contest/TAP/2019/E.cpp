#include <iostream>
#include <string>

using namespace std;

using num = long double;

int main() {
  num total1 = 0, total2 = 0;
  cin >> total1 >> total2;

  num correct1 = 0, correct2 = 0;
  cin >> correct1 >> correct2;

  num result1 = (correct1 / total1 + correct2 / total2) / 2;
  num result2 = (correct1 + correct2) / (total1 + total2);

  if (result1 > result2 ) cout << "A" << endl;
  else if (result1 < result2 ) cout << "B" << endl;
  else cout << "C" << endl;

  return 0;
}