#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  string s;
  cin >> s;
  int cnt[26]={0};

  for(int i=0;i<n;i++)
    cnt[s[i]-'a']++;

  int ans = 0;

  for(int i=0;i<26;i++)
    if(cnt[i] > 0)
      ans+=cnt[i]-1;

  if(n > 26)
  cout << -1 << endl;
  else
  cout << ans << endl;

  
  return 0;
}