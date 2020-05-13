#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  string s,t;
  cin >> s >> t;
  string aux = t.substr(0,t.size()-1);

  if(s == aux)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}