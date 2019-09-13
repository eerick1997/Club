#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

string s;
lli nb, ns, nc, pb, ps, pc, R;
lli bread_needed, sausage_needed, cheese_needed;

lli check( lli middle ){
    lli r = 0;
    
    lli bread = max(bread_needed * middle - nb, 0LL);
    lli sausage = max(sausage_needed * middle - ns, 0LL);
    lli cheese = max(cheese_needed * middle - nc, 0LL);

    r += bread * pb;
    r += sausage * ps;
    r += cheese * pc;
    
    return r;
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    cin >> s;
    cin >> nb >> ns >> nc >> pb >> ps >> pc >> R;

    for( auto c : s ){
        if( c == 'B')
            bread_needed++;
        else if( c == 'S' )
            sausage_needed++;
        else 
            cheese_needed++;
    }

    lli begin = 0, end = max( 2*R, (lli)(1 << 10) ), middle = 0, ans = 0;

    while( begin <= end ){

        middle = ( begin + end ) / 2;
        lli f = check( middle );
        if( f == R ){
            cout << middle << endl;
            return 0;
        } if( check( middle ) < R )
            begin = middle + 1, ans = middle;
        else 
            end = middle - 1;
    } 

    cout << ( ans < 0 ? -1 : ans ) << endl;
    return 0;
}