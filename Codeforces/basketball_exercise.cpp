#include <bits/stdc++.h>

using namespace std;

const int nax = 1e5 + 5;
long long dp[nax][3];
long long vet[nax][2];

int main(){

  int n;
  cin >> n;

  for(int i=1;i<=n;i++)
    cin >> vet[i][0];

  for(int i=1;i<=n;i++)
    cin >> vet[i][1];
    
  for(int i=1;i<=n;i++){
    dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + vet[i][0];
    dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + vet[i][1];
    dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
  }

  cout << max(dp[n][0],max(dp[n][1],dp[n][0])) << endl;
   
  return 0;
}