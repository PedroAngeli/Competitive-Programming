#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,t;
  cin >> n >> t;

  string s1,s2;
  cin >> s1 >> s2;

  string ans;
  ans.resize(n,'\0');

  int k1 = n-t,k2 = n-t;

  for(int i=0;i<n && k1 && k2;i++){
    if(s1[i] == s2[i])
      ans[i] = s1[i],k1--,k2--;
  }

  int pos = 0;

  while(pos < n && k1){
    if(!ans[pos])
      ans[pos] = s1[pos],k1--;

    pos++;
  }

   while(pos < n && k2){
    if(!ans[pos])
      ans[pos] = s2[pos],k2--;

    pos++;
  }

  for(int i=0;i<n;i++){
    if(!ans[i]){
     for(int j=0;j<26;j++)
      if(s1[i] != j+'a' && s2[i] != j+'a'){
        ans[i] = j+'a';
        break;
      }
    }
  }
  
  int t1 = 0;
  int t2 = 0;

  for(int i=0;i<n;i++){
    if(ans[i] != s1[i])
      t1++;
    if(ans[i] != s2[i])
      t2++;
  }

  

  if(t1 == t && t2 == t)
    cout << ans << endl;
  else
    cout << -1 << endl;

  return 0;
}