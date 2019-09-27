#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

vector< lli > bags;
lli popCornBags = 0LL, competitors = 0LL, maxPopcornToEat = 0LL;

bool check( lli time ){
    lli count_competitors = 1;
    lli popCornSum = 0LL;
    lli neededPopcorn = (time * maxPopcornToEat);
    for( lli i = 0LL; i <= popCornBags; i++ ){
        if( bags[ i ] > neededPopcorn )
            return true;

        if( ( popCornSum + bags[ i ] ) <= neededPopcorn )
            popCornSum += bags[ i ];
        else 
            popCornSum = bags[ i ], count_competitors++;    
    }
    return !(count_competitors <= competitors);
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    lli begin, end, middle, ans = 1, MAX = -1;
    cin >> popCornBags >> competitors >> maxPopcornToEat;
    bags.resize( popCornBags + 1, 0LL );
    for( lli i = 0LL; i < popCornBags; i++ )
        cin >> bags[ i ], MAX = max( MAX, bags[ i ] );

    //Binary search
    begin = 0, end = 1 << 30;
    while( begin <= end ){
        middle = ( begin + end ) / 2;
        if( check( middle ) )
            begin = middle + 1;
        else 
            end = middle - 1, ans = middle;
    }

    if( competitors >= popCornBags )
        ans = ceil((double)MAX / (double)maxPopcornToEat);
        
    cout << (ans == 0 ? 1 : ans) << endl;
    
    return 0;
}