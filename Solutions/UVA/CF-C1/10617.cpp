#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

string s;
int n;
long long dp[65][65];

long long solve(int l,int r){

  if(l > r)
    return 0;

  if(dp[l][r] != -1)
    return dp[l][r];

  if(s[l] == s[r])
    return dp[l][r] = 1 + solve(l+1,r) + solve(l,r-1);

  return dp[l][r] = solve(l+1,r) + solve(l,r-1) - solve(l+1,r-1);
}

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  
  while(t--){
    cin >> s;
    n = s.size();
    memset(dp,-1,sizeof dp);
    
    cout << solve(0,n-1) << endl;
  }
  
  
  return 0;
}