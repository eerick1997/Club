#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio( false );
  cout.tie( nullptr );
  cin.tie( nullptr );
  int nPrecints, nDistricts;
  int district, votesA, votesB;
  map< int, pair<int, int> > precints;
  cin >> nPrecints >> nDistricts;
  double T = 0;
  while( nPrecints-- ){
    cin >> district >> votesA >> votesB;
    T += votesA + votesB;
    precints[ district ].first += votesA;
    precints[ district ].second += votesB;
  }

  int tVotes = 0;
  int Wa = 0, Wb = 0;
  double efficiency = 0;
  for( auto e : precints ){
    tVotes = e.second.first + e.second.second;

    if( e.second.first > e.second.second ){
      Wa = fabs((( tVotes / 2 ) + 1) - e.second.first);
      Wb = e.second.second;
      cout << "A ";
      cout << Wa << ' ';
      cout << Wb << endl;
    } else {
      Wb = fabs((( tVotes / 2 ) + 1) - e.second.second);
      Wa = e.second.first;
      cout << "B ";
      cout << Wa << ' ';
      cout << Wb << endl;
    }
    efficiency += ( (Wa - Wb) / T );
  }
  cout << fixed;
  cout << setprecision(10);
  cout << fabs(efficiency) << endl;
  return 0;
}