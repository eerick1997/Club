#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

vector< lli > bags;
lli popCornBags, competitors, maxPopcornToEat;

bool check( lli middle ){
    cout << endl << middle << endl;
    int count_competitors = 0;
    int popCornSum = 0;
    int neededPopcorn = middle * maxPopcornToEat;

    for( int i = 0; i < popCornBags; i++ ){
        cout << popCornSum << " ";
        if( popCornSum + bags[ i ] <= neededPopcorn )
            popCornSum += bags[ i ];
        else 
            popCornSum = bags[ i ], count_competitors++;
         
    }
    cout << endl;
    cout << count_competitors << endl;
    return (count_competitors <= competitors );
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    lli  begin, end, middle, ans = -1;
    cin >> popCornBags >> competitors >> maxPopcornToEat;
    bags.resize( popCornBags );
    for( int i = 0; i < popCornBags; i++ )
        cin >> bags[ i ];
    //Binary search
    begin = 0, end = 10;
    while( begin <= end ){
        middle = ( begin + end ) >> 1;
        if( !check( middle ) )
            begin = middle + 1, ans = middle;
        else 
            end = middle - 1;
    }    
    cout << ans << endl;
    return 0;
}