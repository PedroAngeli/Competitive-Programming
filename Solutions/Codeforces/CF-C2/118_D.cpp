#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n1,n2,k1,k2;
int dp[105][105][15][15];
const int mod = 1e8;

int solve(int s1,int s2,int qtd1,int qtd2){
  if(qtd1 > k1 || qtd2 > k2)
    return 0;

  if(s1 == 0 && s2 == 0)
    return 1;

  int& state = dp[s1][s2][qtd1][qtd2];
  
  if(state != -1)
    return state;

  int a = 0;

  if(s1 > 0)
    a += solve(s1-1,s2,qtd1+1,0);
  if(s2 > 0)
    a += solve(s1,s2-1,0,qtd2+1);
  a %= mod;

  return state = a;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n1 >> n2 >> k1 >> k2;

  memset(dp,-1,sizeof dp);
  cout << solve(n1,n2,0,0) << endl;
}