#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

vector< pair< lli, lli > > trees;
vector< lli > Distance; 

int main(){
	ios::sync_with_stdio( false );
	cout.tie( nullptr );
	cin.tie( nullptr );
	int n;
	lli ans = 0;
	cin >> n;
	trees.assign( n, {0, 0} );
	for( int i = 0; i < n; i++ )
		cin >> trees[ i ].first >> trees[ i ].second;
	
	if( n == 1 ){
		cout << 1 << endl;
		return 0;
	} else if( n == 2 ){
		cout << n << endl;
		return 0;
	}

	Distance.resize( n - 1 );
	for( int i = 1; i < n; i++ )
		Distance[ i - 1 ] = abs( trees[ i ].first - trees[ i - 1 ].first );

	for( int i = 1; i < n - 1; i++ ){
		lli current = trees[ i ].second;
		if( current < Distance[ i - 1 ] )
			ans++, Distance[ i - 1 ] -= current;
		else if( current < Distance[ i ] )
			ans++, Distance[ i ] -= current;
	}

	cout << ans + 2 << endl;
	return 0;
}