#include <bits/stdc++.h>

using namespace std;

int n;
const int mod = 1e9 + 7;
const int nax = 1e6 + 7;
int dp[nax];


int main(){

  cin >> n;

  dp[0] = 1;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=6;j++){
      if(i - j >= 0)
        dp[i] = ((dp[i] % mod) + (dp[i-j] % mod)) % mod;
      else
        break;
    }
  }

  cout << dp[n] << endl;

  return 0;
}