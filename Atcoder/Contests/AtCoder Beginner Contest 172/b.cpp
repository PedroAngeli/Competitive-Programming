#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  string s,t;
  cin >> s >> t;
  int n = s.size();
  int ans = 0;

  for(int i=0;i<n;i++)
    if(s[i] != t[i])
      ans++;
  

  cout << ans << endl;
 
  return 0;
}