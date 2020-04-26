#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool func (string s1, string s2){
  int n = s1.size();
  int m = s2.size();

  if(n > m)
    return true;
  else if(m > n)
    return false;
  
  int i=0;
  int j=0;

  while(i < n && j < m){
    if(s1[i] > s2[j])
      return true;

    i++,j++;
  }

  return false;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  string aux = "1";
  int ans = 0;

  while(func(s,aux)){
    ans++;
    aux += "00";
  }

  cout << ans << endl;

  return 0;
}