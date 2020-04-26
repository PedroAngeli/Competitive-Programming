#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 +7;

int main(){

  int n,x;

  cin >> n >> x;

  int val[n];
  int dp[n][x+1];

  for(int i=0;i<n;i++)
    for(int j=0;j<=x;j++)
      dp[i][j] = INF;

  for(int i=0;i<n;i++)
    cin >> val[i];

  for(int i=0;i<n;i++){
    for(int j=0;j<=x;j++){
      if(j == 0){
        dp[i][j] = 0;
      }else{
        if(j-val[i] >= 0){
          if(i > 0){
            dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-val[i]]);
          }else{
            dp[i][j] = 1 + dp[i][j-val[i]];
          }
        }else if(i > 0){
          dp[i][j] = dp[i-1][j];
        }
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<=x;j++)
      cout << dp[i][j] << " ";
    cout << endl;
  }
    

  if(dp[n-1][x] >= INF)
    dp[n-1][x] = -1;

  cout << dp[n-1][x] << endl; 

  return 0;
}