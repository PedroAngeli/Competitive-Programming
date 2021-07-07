#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  string s;
  cin >> s;
  const int mod = 1e9 + 7;

  unordered_map <char,int> mp;
  int mx = 0;

  for(int i=0;i<n;i++)
    mp[s[i]]++, mx=max(mx,mp[s[i]]);

  int cnt = (mp['A'] == mx) + (mp['C'] == mx) + (mp['G'] == mx) + (mp['T'] == mx);

  long long ans = 1;

  for(int i=0;i<n;i++){
    ans = (ans*cnt)%mod;
  } 

  cout << ans << endl;


  return 0;
}