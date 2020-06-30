#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    string cur_name, ans_name, buffer;
    int32_t n_requirements, n_proposals, m_proposals, RFP = 0, ans_marks = -1;
    double cur_price, ans_price = 1e10;


    while (cin >> n_requirements >> n_proposals and n_requirements and n_proposals ) {
        ans_marks = -1, ans_price = 1e10;

        RFP++;
        if(RFP != 1)
            cout << "\n\n";

        cin.ignore();
        for( int i = 0; i < n_requirements; i++ )
            getline( cin, buffer );

        for( int i = 0; i < n_proposals; i++ ) {
            
            getline( cin, cur_name );
            cin >> cur_price >> m_proposals;

            cin.ignore();
            for( int j = 0; j < m_proposals; j++ )
                getline( cin, buffer );

            if( m_proposals > ans_marks or ( m_proposals == ans_marks and cur_price < ans_price ) ){
                ans_name = cur_name;
                ans_marks = m_proposals;
                ans_price = cur_price;
            }

        }

        cout << "RFP #" << RFP << endl;
        cout << ans_name;
    }
    cout << endl;
    return 0;
}