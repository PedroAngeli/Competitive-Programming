#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,m,x,y;
const int nax = 1e3 + 5;
const int INF = 1e9 + 7;
int pretos[nax];
int brancos[nax];
int prefPreto[nax];
int prefBranco[nax];
int dp[nax][3];

int queryPreto(int i,int j){
  if(i == 0)
    return prefPreto[j];

  return prefPreto[j] - prefPreto[i-1];
}

int queryBranco(int i,int j){
  if(i == 0)
    return prefBranco[j];

  return prefBranco[j] - prefBranco[i-1];
}

int solve(int i, int last){
  int ans = INF;

  if(i >= m)
    return 0;

  if(dp[i][last] != -1)
    return dp[i][last]; 

   for(int k=x;k<=y;k++){
      if(i + k - 1 < m){
        if(last == 0){
          ans = min(ans, queryBranco(i,i+k-1) + solve(i+k,1));
        }else if(last == 1){
          ans = min(ans, queryPreto(i,i+k-1) + solve(i+k,0));
        }else{
          ans = min(ans, queryBranco(i,i+k-1) + solve(i+k,1));
          ans = min(ans, queryPreto(i,i+k-1) + solve(i+k,0));
        }
      }
    }

  return dp[i][last] = ans;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> x >> y;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char c;
      cin >> c;
      if(c == '#')
        pretos[j]++;
      else
        brancos[j]++;
    }
  }

  prefBranco[0] = brancos[0];
  prefPreto[0] = pretos[0];

  for(int i=1;i<m;i++){
    prefBranco[i] = prefBranco[i-1] + brancos[i];
    prefPreto[i] = prefPreto[i-1] + pretos[i];
  }  

  memset(dp,-1,sizeof dp);

  cout << solve(0,2) << endl;

  return 0;
}