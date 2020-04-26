#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int dp[105][3];
int a[105];
int n;


int solve(int i,int op){
  if(i == n)
    return 0;

  if(dp[i][op] != -1)
    return dp[i][op];

  if(op == 2){
    if(a[i] == 0)
      return dp[i][op] = 1 + solve(i+1,2);

    if(a[i] == 3)
      return dp[i][op] = min(solve(i+1,0),solve(i+1,1));

    if(a[i] == 1)
      return dp[i][op] = solve(i+1,1);

    return dp[i][op] = solve(i+1,0);

  }
  if(op == 0){
    if(a[i] == 3 || a[i] == 1)
      return dp[i][op] = solve(i+1,1);
    
    return dp[i][op] = 1 + solve(i+1, 2);
  }

  if(op == 1){
    if(a[i] == 2 || a[i] == 3)
      return dp[i][op] = solve(i+1,0);

    return dp[i][op] = 1 + solve(i+1,2);
  }  
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for(int i=0;i<n;i++)
    cin >> a[i];

  memset(dp,-1,sizeof dp);
  
  cout << solve(0,2) << endl;

  return 0;
}