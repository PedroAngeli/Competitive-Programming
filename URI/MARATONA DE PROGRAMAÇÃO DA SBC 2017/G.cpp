#include <bits/stdc++.h>

using namespace std;

int T,M,N;
const int nax = 1e5 + 5;
const int mod = 1e9 + 7;
int dp[55][nax];

int solve(int t, int d){
  if(d < M || d > N)
    return 0;
  
  if(t == T)
    return 1;

  if(dp[t][d] != -1)
    return dp[t][d];

  int a = solve(t+1, d+1);
  int b = solve(t+1, d-1);

  return dp[t][d] = ((a % mod) + (b % mod)) % mod;
}

int main(){

  cin >> T >> M >> N;
  int sum = 0;
  
  memset(dp, -1, 55*nax*sizeof(int));
  for(int i=M;i<=N;i++)
  sum = ((sum % mod) + (solve(1,i) % mod)) % mod;

  cout << sum << endl;

  return 0;
}