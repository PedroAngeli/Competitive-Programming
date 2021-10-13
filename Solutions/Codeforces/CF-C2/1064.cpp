#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int cnt[26];

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  string s;
  cin >> n >> s;
  for(int i=0;i<n;i++)
    cnt[s[i]-'a']++;
  
  string ans;

  for(int i=0;i<26;i++)
    if(cnt[i])
      for(int k=0;k<cnt[i];k++)
        ans.push_back(i+'a');

    cout << ans << endl;
      
  return 0;
}