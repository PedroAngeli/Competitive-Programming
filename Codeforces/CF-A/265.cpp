#include <bits/stdc++.h>

using namespace std;


int main(){

  string s, t;

  cin >> s >> t;

  int idx = 0;

  for(int i=0;i<t.size();i++){
    if(t[i] == s[idx])
      idx++;
  }

  cout << idx + 1 << endl;
  return 0;
}