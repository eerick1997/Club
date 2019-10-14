#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    int H, W, ans = 0;
    cin >> H >> W;
    vector< vector< char > > grid(H + 2, vector< char >( W + 2, '.') );

    for( int i = 1; i <= H; i++ )
        for( int j = 1; j <= W; j++ )
            cin >> grid[ i ][ j ];

    /*cout << endl;
    for( int i = 0; i < grid.size(); i++ ){
        for( int j = 0; j < grid[0].size(); j++ )
            cout << grid[ i ][ j ];
        cout << endl;
    }*/
    for( int i = 1; i <= H; i++ ){
        for( int j = 1; j <= W; j++ ){
            int left = -1, right = -1, top = -1, bottom = -1;
            int center_i, center_j;
            if( grid[ i ][ j ] == '*' ){

                center_i = i, center_j = j;
                bool flag = false;
                while( ( grid[ center_i ][ center_j ] == '*' ) && ( ( grid[ center_i ][ center_j + 1] == '.'  &&  grid[ center_i ][ center_j - 1] == '.' ) || !flag ) )
                    center_i++, bottom++, flag = true;

                flag = false;
                center_i = i, center_j = j;
                while( ( grid[ center_i ][ center_j ] == '*' ) && ( ( grid[ center_i ][ center_j + 1] == '.'  &&  grid[ center_i ][ center_j - 1] == '.' ) || !flag ) )
                    center_i--, top++, flag = true;
                
                flag = false;
                center_i = i, center_j = j;
                while(  ( grid[ center_i ][ center_j ] == '*' ) && ( ( grid[ center_i + 1 ][ center_j ] == '.'  &&  grid[ center_i - 1 ][ center_j ] == '.' ) || !flag ) )
                    center_j++, right++, flag = true;
                
                flag = false;
                center_i = i, center_j = j;
                while(  ( grid[ center_i ][ center_j ] == '*' ) && ( ( grid[ center_i + 1 ][ center_j ] == '.'  &&  grid[ center_i - 1 ][ center_j ] == '.' ) || !flag ) )
                    center_j--, left++, flag = true;

                //cout << i << " " << j << endl;
                //cout << "left " << left << " | right " << right << " | top " << top << " | bottom " << bottom << endl;
                if( left > 0 && right > 0 && top > 0 && bottom > 0){
                    if( left == right && left == top && bottom > left ){
                        //cout << "left " << left << " | right " << right << " | top " << top << " | bottom " << bottom << endl;
                        ans++;
                    }
                }
            }
        }
        //cout << endl;
    }

    cout << ans << endl;
    return 0;
}