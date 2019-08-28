#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    int n;
    cin >> n;
    if( n <= 3 ) 
        cout << "NO" << endl;
    else if( n == 4 ){
        cout << "YES" << endl;
        cout << "4 * 3 = 12" << endl;
        cout << "12 * 2 = 24" << endl;
    } else if( n == 5 ){
        //1 2 3 4 5
        cout << "YES" << endl;
        //1 2 3 20
        cout << "5 * 4 = 20" << endl;
        //2 4 20
        cout << "3 + 1 = 4" << endl;
        cout << "" << endl;
    } else {
        map< int, int > numbers;
        for( int i = 1; i <= n; i++ )
            numbers[ i ] = 1;
        
        numbers[ 4 ]--;
        numbers[ 6 ]--;

        cout << "6 * 4 = 24" << endl;
        int i = n, j = n - 1;
        for( ; i >= 0 && j >= 0; ){
            
            while( numbers[ i ] != 0 && i >= 0 && j != (i - 1) ){
                i--;
            }
            j = i - 1;

            while( numbers[ j ] != 0 && j >= 0 && j != i ){
                j--;
            }
        
            numbers[ abs(i - j) ]++;
            numbers[ i ]--;
            numbers[ j ]--;
            cout << i << " - " << j << " = " << i - j << endl;
        }
        for( int i = 0; i < numbers[ 1 ]; i++)
            cout << "24 * 1 = 24" << endl;
    }
    return 0;
}