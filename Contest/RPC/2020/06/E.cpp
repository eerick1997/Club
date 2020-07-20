#include <bits/stdc++.h>

using namespace std;

const auto endline = '\n';

struct student {
  string name;
  bool available = true;
};

auto get_num_words() -> int {
  auto data_raw = string {};
  cin.ignore();
  getline(cin, data_raw);

  istringstream words_stream(data_raw);
  auto it = istream_iterator<string> {words_stream};
  auto words = vector<string>(it, istream_iterator<string>());
  return words.size();
}

auto get_student() -> vector<student> {
  int num_students;
  cin >> num_students;
  auto students = vector<student>(num_students);
  for (auto& s : students) cin >> s.name;

  return students;
}

int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  const auto number_of_words = get_num_words();
  auto students = get_student();

  bool choosing_team1 = true;
  auto team1 = vector<string> {}, team2 = vector<string> {};

  auto get_next = [&](const int x) { return (x + 1) % students.size(); };

  auto current_student = 0, num_student_passed = 0;
  for (int available = students.size(); available > 0;
       current_student = get_next(current_student)) {
    if (not students[current_student].available) continue;
    num_student_passed++;

    if ((num_student_passed % number_of_words) != 0) continue;
    auto& team = choosing_team1 ? team1 : team2;
    team.push_back(students[current_student].name);
    students[current_student].available = false;
    available--;
    choosing_team1 = !choosing_team1;
  }

  cout << team1.size() << endline;
  for (const string names : team1) cout << names << endline;

  cout << team2.size() << endline;
  for (const string names : team2) cout << names << endline;
}