#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e3 + 5;
int p[nax];
int n;
const int INF = 1e9 + 7;
int dp[nax][nax];

int solve(int l, int r){
  int ret = INF;
  int len = r-l;

  if(dp[l][r] != -1)
    return dp[l][r];

  for(int i=0;i<n;i++){
    if(p[i] > l && p[i] < r)
        ret = min(ret,len + solve(l,p[i]) + solve(p[i],r)); 
  }

  if(ret == INF)
    ret = 0;

  return dp[l][r] = ret;
}
int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int l;

  while(cin >> l && l){
    cin >> n;
    memset(dp,-1,sizeof dp);

    for(int i=0;i<n;i++)
      cin >> p[i];

    cout << "The minimum cutting is " <<  solve(0,l) << "." << endl;
  }
  
  return 0;
}