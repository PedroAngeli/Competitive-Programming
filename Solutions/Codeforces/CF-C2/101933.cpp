#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int mod = 1e9 + 7;
int dp[2501][2501];

int solve(int n,int k){
  if(n < k || k == 1)
    return 0;
  if(n == 2)
    return 2;

  if(dp[n][k] != -1)
    return dp[n][k];
  
  return dp[n][k] = (1LL * k * solve(n-1,k-1) +  1LL * (k-1) * solve(n-1,k))%mod;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,k;  
  cin >> n >> k;

  for(int i=1;i<=n-1;i++){
    int u;
    cin >> u;
  }
  memset(dp,-1,sizeof dp);
  cout << solve(n,k) << endl;
  
  return 0;
}