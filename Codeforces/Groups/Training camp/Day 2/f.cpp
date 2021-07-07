#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int n,k;
const int nax = 2e3 + 5;
int dp[nax][nax];
const int mod = 1e9 + 7;

int solve(int i,int cur){
  if(cur > n)
    return 0;

  if(i == k)
    return 1;
  
  int& state = dp[i][cur];

  if(state != -1)
    return state;

  int sum = 0;
  int mult = 1;

  while(cur*mult <= n){
      sum += solve(i+1,cur*mult);
      sum %= mod;
      mult++;
  }

  return state = sum;
}
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  cin >> n >> k;
  int sum = 0;
  memset(dp,-1,sizeof dp);

  for(int i=1;i<=n;i++){
    sum += solve(1,i);
    sum %= mod;
  }

  cout << sum << endl;

  return 0;
}