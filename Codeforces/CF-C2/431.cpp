#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int n,k,d;
int dp[105][105];
const int mod = 1e9 + 7;

int solve(int sum,int qtdD){
  if(sum > n)
    return 0;

  if(sum == n && qtdD > 0)
    return 1;

  int& state = dp[sum][qtdD];

  if(state != -1)
    return state;

  int ways = 0;

  for(int i=1;i<=k;i++){
    ways += solve(sum+i,qtdD+(i >= d));
    ways %= mod;
  }

  return state = ways%mod;
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 

  cin >> n >> k >> d;
  memset(dp,-1,sizeof dp);
  cout << solve(0,0) << endl;
 
  return 0;
}