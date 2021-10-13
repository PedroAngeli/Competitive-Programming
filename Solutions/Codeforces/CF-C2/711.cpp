#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,m,k;
const int nax = 105;
int color[nax];
long long cost[nax][nax];
const long long INF = 1e18;
long long dp[nax][nax][nax];

long long solve(int i,int l,int s){
  if(s > k)
    return INF;

  if(i > n){
    if(s != k)
      return INF;
    return 0;
  }

  if(dp[i][l][s] != -1)
    return dp[i][l][s];
  
  if(color[i]){
    if(color[i] == l)
      return dp[i][l][s] = solve(i+1,l,s);
    return dp[i][l][s] =  solve(i+1,color[i],s+1);
  }

  long long ret = INF;

  for(int c=1;c<=m;c++){
    if(c == l)
      ret = min(ret,cost[i][c] + solve(i+1,c,s));
    else
      ret = min(ret,cost[i][c] + solve(i+1,c,s+1));
  }

  return dp[i][l][s] = ret;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin >>  n>> m >> k;

  for(int i=1;i<=n;i++)
    cin >> color[i];

  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin >> cost[i][j];

  memset(dp,-1,sizeof dp);

  long long ans = solve(1,0,0);

  if(ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;
  
  return 0;
}