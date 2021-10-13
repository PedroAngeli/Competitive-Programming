#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18L + 5;

int main(){

  int N, W;

  cin >> N >> W;
  
  vector <int> w(N);
  vector <int> v(N);
  
  for(int i=0;i<N;i++){
    cin >> w[i] >> v[i];
  }

  int sum = 0;

  for(int i=0;i<N;i++)
    sum += v[i];

  vector <vector <long long> > dp(N);

  for(int i=0;i<N;i++)
    dp[i].assign(sum+1,INF);

  for(int i=0;i<N;i++)
    dp[i][0] = 0;

  dp[0][v[0]] = w[0];

  for(int i=1;i<N;i++){
    for(int j=0;j<=sum;j++){
      if(j-v[i] >= 0){
        dp[i][j] = min(dp[i-1][j], w[i] + dp[i-1][j-v[i]]);
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  long long ans  = 0;

  for(long long i = 0;i<=sum;i++){
    if(dp[N-1][i] <= W)
      ans = max(ans,i);  
  }

  cout << ans << endl;

  return 0;
}