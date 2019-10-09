#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int  main (){
  string s;
  int n;
  cin>>n;
  map<char, bool>mapa;

  for(int i = 0; i < n; i++){
    char c;
    cin>>c;
    if(c == 'T')mapa['A'+i] = true;
    else mapa['A'+i] = false;
  }

  cin.ignore();
  getline(cin, s);

  stack<char>pila;
  bool a, b;
  for(int i = 0; i < s.size(); i++){

    if(s[i] == ' '){
      continue;
    }
    if(s[i] == '*'){
      a = pila.top();
      pila.pop();
      b = pila.top();
      pila.pop();

      pila.push(a&b);

    }else if (s[i] == '+'){
      a = pila.top();
      pila.pop();
      b = pila.top();
      pila.pop();

      pila.push(a|b);

    }else if(s[i] == '-'){
      a = pila.top();
      pila.pop();
      pila.push(not a);
    }else{
      pila.push(mapa[s[i]]);
    }
  }


  cout<<(pila.top() ? 'T' : 'F')<<endl;

  return 0;
}