#include <bits/stdc++.h>

using namespace std;

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int number_of_stores, k;
    cin >> number_of_stores >> k;

    auto x = map<string, set<int>> {};
    string thing;
    int store_id;

    for (int i = 0; i < k; i++) {
        cin >> store_id >> thing;
        x[thing].insert(store_id);
    }

    int number_of_objects;
    cin >> number_of_objects;

    auto visit = vector<set<int>*> {};
    for (int i = 0; i < number_of_objects; i++) {
        cin >> thing;
        visit.push_back(&x[thing]);
    }

    int current = -1;
    for (int i = 0; i < number_of_objects; i++) {
        auto& wea = *visit[i];
        auto new_min = wea.begin();

        while (*new_min < current) {
            new_min++;
            if (new_min == wea.end()) {
                cout << "impossible" << endl;
                exit(0);
            }
        }

        current = *new_min;
    }

    current = -1;
    bool cheat = true;
    for (int i = 0; i < number_of_objects; i++) {
        auto& wea = *visit[i];
        auto new_min = wea.begin();

        while (*new_min < current) {
            new_min++;
        
            if (new_min == wea.end()) {
                cout << "unique" << endl;
                exit(0);
            }
        }

        if (cheat) {
            new_min++;
            if (new_min == wea.end()) new_min--;
            else cheat = false;
        }

        current = *new_min;
    }

    if (cheat) cout << "unique" << endl;
    else cout << "ambiguous" << endl;


    return 0; 
}