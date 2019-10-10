#include <bits/stdc++.h>

using namespace std;
string str;
vector< int > position[ 26 ];

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    cin >> str;
    int ans = 0;

    for( int i = 0; i < str.size(); i++ )
        position[ str[ i ] - 'a' ].push_back( i );

    for( int begin = 0; begin < str.size(); begin++ ){
        //Find the index of the next element to me
        auto findNextToMe = upper_bound( position[ str[ begin ] - 'a' ].begin(), position[ str[ begin ] - 'a' ].end(), begin );
        //Move through all the bucket
        for( int j = 0; j < 26; j++ ){
            //I don't need the same character we need one different
            if( j != (str[ begin ] - 'a') ){
                //It is a possible solution we need to find them
                auto end = upper_bound( position[ j ].begin(), position[ j ].end(), begin );
                //Maybe doesn't exist a character 
                if( end != position[ j ].end() ){
                    //cout << "begin = " << ( begin ) << " | end = " << (*end) << " | findNextToMe " << (*findNextToMe) <<endl;
                    if( ( (*findNextToMe) > ( *end ) ) || ( findNextToMe == position[ str[ begin ] - 'a' ].end() ) )
                        ans++;
                }
            }
        }      

    }

    cout << ans << endl;

    return 0;
}