#include <bits/stdc++.h>

using namespace std;

int main(){

  int N, W;

  cin >> N >> W;
  
  vector <int> w(N);
  vector <int> v(N);
  long long dp[N][W+1] = {{0}};
  
  for(int i=0;i<N;i++){
    cin >> w[i] >> v[i];
  }

  for(int i=0;i<=W;i++)
    dp[0][i] = w[0] <= i ? v[0] : 0;
  
  for(int i=1;i<N;i++){
    for(int j=0;j<=W;j++){
      if(j-w[i] >=0 ){
        dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j-w[i]]);
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout << dp[N-1][W] << endl;

  return 0;
}