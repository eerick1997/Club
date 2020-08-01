#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<char>> &m) {
    int n = m.size();
    cout << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cout << m[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int test_cases, n_countries;
    vector<vector<char>> m_outcoming, m_incoming, m_ans;
    string incoming, outcoming;

    cin >> test_cases;

    for(int t = 1; t <= test_cases; t++) {
        cin >> n_countries;

        m_outcoming.assign(n_countries, vector<char>(n_countries));
        m_incoming.assign(n_countries, vector<char>(n_countries));
        m_ans.assign(n_countries, vector<char>(n_countries));

        cin >> incoming >> outcoming;

    
        for(int i = 0; i < n_countries; i++) {
            for(int j = 0; j < n_countries; j++) {
                m_outcoming[i][j] = (i == j ? 'Y' : outcoming[i]);
                m_incoming[j][i] = (i == j ? 'Y' : incoming[i]);
            }
        }

        cout << "outcoming";
        print(m_outcoming);
        cout << "incoming";
        print(m_incoming);

        for(int i = 0; i < n_countries; i++) {
            for(int j = 0; j < n_countries; j++) {
                if(m_incoming[i][j] == 'Y' and m_outcoming[i][j] == 'Y') {
                    if(abs(i - j) == 1)
                        m_ans[i][j] = 'Y';
                    else if(i == j)
                        m_ans[i][j] = 'Y';
                    else {
                        if(m_incoming[j - 1][i] == 'Y' and m_outcoming[i][j - 1] == 'Y')
                            m_ans[i][j] = 'Y';
                        else 
                            m_ans[i][j] = 'N';
                    }
                } else 
                    m_ans[i][j] = 'N';
            }
        }

        cout << "ans";
        print(m_ans);

        /*for(int i = 0; i < n_countries; i++) {
            for(int j = 0; j < n_countries; j++) {
                if(abs(i - j) > 1) {
                    adjacency_matrix[j][i] = 'N';
                    continue;
                } else if(i == j) {
                    adjacency_matrix[j][i] == 'Y';   
                    continue;
                } 
                adjacency_matrix[j][i] = incoming[i];
            }
        }

        for(int i = 0; i < n_countries; i++) {
            for(int j = 0; j < n_countries; j++) {
                if(abs(i - j) > 1) {
                    adjacency_matrix[i][j] = 'N';
                    continue;
                } else if(i == j) {
                    adjacency_matrix[i][j] == 'Y';   
                    continue;
                } 
                if(adjacency_matrix[i][j] == 'Y' and outcoming[i] == 'Y')
                    adjacency_matrix[i][j] == 'Y';
            }
        }

        /*for(int i = 0; i < n_countries; i++) {
            for(int j = 0; j < n_countries; j++) {
                if(abs(i - j) > 1) {
                    if(adjacency_matrix[i][j] == 'Y' and outcoming[i - 1] == 'Y')
                        adjacency_matrix[i][j] = 'Y';
                    continue;
                } else if(i == j) {
                    adjacency_matrix[i][j] == 'Y';
                    continue;
                }
            }
        }*/
        /*cout << "Case #" << t << endl;
        for(int i = 0; i < n_countries; i++) {
            for(int j = 0; j < n_countries; j++) {
                cout << adjacency_matrix[i][j];
            }
            cout << endl;
        }*/
        m_outcoming.clear();
        m_incoming.clear();
        m_ans.clear();
    }
    return 0;
}