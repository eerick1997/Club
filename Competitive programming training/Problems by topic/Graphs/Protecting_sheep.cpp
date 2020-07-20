#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int R, C;
    char buffer, pasture[505][505];
    int can_eat = 0;

    cin >> R >> C;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> buffer;
            pasture[i][j] = (buffer == '.') ? 'D' : buffer;
        }
    }

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            if(pasture[i][j] == 'W') {
                const char left = pasture[i - 1][j];
                const char right = pasture[i + 1][j];
                const char up = pasture[i][j + 1];
                const char down = pasture[i][j - 1];
                if(left == 'S')
                    can_eat++;
                if(right == 'S')
                    can_eat++;
                if(up == 'S')
                    can_eat++;
                if(down == 'S')
                    can_eat++;

            }
        }
    }

    if(can_eat == 0) {
        cout << "Yes\n";
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++)
                cout << pasture[i][j];
            cout << endl;
        }
    } else 
        cout << "No\n";
    
    return 0;
}