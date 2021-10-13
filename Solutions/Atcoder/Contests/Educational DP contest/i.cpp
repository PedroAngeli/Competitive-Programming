#include <bits/stdc++.h>

using namespace std;

const int nax = 3000;
double dp[nax][nax]; //guarda a probabilidade de sair j caras em i moedas

int main(){

  int n;

  cin >> n;

  vector <double> prob(n+1);

  for(int i=1;i<=n;i++)
    cin >> prob[i];

    dp[0][0] = 1;
    dp[1][0] = 1 - prob[1];
    for(int i = 2; i <= n; i++)
        dp[i][0] = dp[i - 1][0] * (1 - prob[i]);

  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      dp[i][j] = prob[i] * dp[i-1][j-1] + (1-prob[i]) * dp[i-1][j];
    }
  }

  double ans = 0;

  for(int i=(n/2) + 1;i<=n;i++)
    ans += dp[n][i];

  cout << setprecision(10) << ans << endl;

  return 0;
}