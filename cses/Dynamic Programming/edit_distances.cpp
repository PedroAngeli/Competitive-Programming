#include <bits/stdc++.h>

using namespace std;

const int nax = 5*1e3 + 5;
int dp[nax][nax];

int main(){

  string s,t;

  cin >> s >> t;

  for(int i=0;i<nax;i++)
    dp[0][i] = dp[i][0] = i;

  for(int i=1;i<=t.size();i++){
    for(int j=1;j<=s.size();j++){
      if(t[i-1] == s[j-1]){
        dp[i][j] = dp[i-1][j-1];
      }else{
        dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
      }
    }
  }

  cout << dp[t.size()][s.size()] << endl;

  return 0;
}