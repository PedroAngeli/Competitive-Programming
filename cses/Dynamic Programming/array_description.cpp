#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(){

  int n,m;

  cin >> n >> m;

  int vet[n];
  int dp[n][m+1];

  memset(dp, 0, sizeof dp);

  for(int i=0;i<n;i++) 
    cin >> vet[i];

  for(int i=1;i<=m;i++){
    if(i == vet[0]){
      dp[0][i] = 1;
    }else if(vet[0] == 0){
      dp[0][i] = 1;
    }
  }

  for(int i=1;i<n;i++){
    for(int j=1;j<=m;j++){
      for(int k=max(1,j-1);k<=min(m,j+1);k++){
        if(vet[i] == 0){
          dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
        }else if(j == vet[i]){
          dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
        }
      }
    }
  }

  int ans = 0;

  for(int i=1;i<=m;i++)
    ans = (ans + dp[n-1][i])%mod;

  cout << ans << "\n";

  return 0;
}