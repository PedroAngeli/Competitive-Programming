#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  string s1;
  string s2;

  int ncase = 1;
  
  while(getline(cin,s1)&&s1[0]!='#'){
    
    getline(cin,s2);
    int n = s1.size();
    int m = s2.size();

    int dp[n+1][m+1];

    memset(dp, 0,sizeof dp);

    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++){
        if(s1[i-1] == s2[j-1])
          dp[i][j] = 1 + dp[i-1][j-1];
        else
          dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }

    cout << "Case #" << ncase++ << ": you can visit at most " << dp[n][m] << " cities." << endl; 
  }
  return 0;
}