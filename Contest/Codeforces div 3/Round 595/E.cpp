#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

vector< lli > powersOfThree( 38 );

string decimalToBaseB(lli n, lli b){
	string ans = "";
	lli d;
	do{
		d = n % b;
		if(0 <= d && d <= 9) ans = (char)(48 + d) + ans;
		else if(10 <= d && d <= 35) ans = (char)(55 + d) + ans;
		n /= b;
	}while(n != 0);
	return ans;
}

lli baseBtoDecimal(const string & n, lli b){
	lli ans = 0;
	for(const char & d : n){
		if(48 <= d && d <= 57) ans = ans * b + (d - 48);
		else if(65 <= d && d <= 90) ans = ans * b + (d - 55);
		else if(97 <= d && d <= 122) ans = ans * b + (d - 87);
	}
	return ans;
}

int main(){
    
    int q;
    cin >> q;

    cout << endl;
    while( q-- ){
        //vector< bool > visited( 38, false );
        
        lli n;
        cin >> n;

        string B = decimalToBaseB( n, 3 );
        int size = B.size();

        for( int i = 0; i < ( 30 - size ); i++ )
            B = "0" + B;
       
       //cout << B << endl;
        bool flag = false;

        for( char c : B ){
            if( c == '2' )
                flag = true;
        }

        if( !flag )
            cout << n << endl;
        else {
            for( int i = B.size() - 1; i >= 0; i-- ){
                if( B[ i ] == '2' ){
                    for( int j = i; j >= 0; j-- ){
                        if( B[ j ] == '2')
                            B[ j ] = '0';
                        else if( B[ j ] == '1' ){
                            B[ j ] = '2';
                            break;
                        } else {
                            B[ j ] = '1';
                            break;
                        }
                    }
                }
            }
        }
        //cout << B << endl;
        cout << baseBtoDecimal( B, 3 ) << endl;

    }
    return 0;
}