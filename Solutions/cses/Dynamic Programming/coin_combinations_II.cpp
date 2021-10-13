#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 +7;

int main(){

  int n,x;

  cin >> n >> x;

  int val[n];
  int dp[x+1] = {0};

  for(int i=0;i<n;i++)
    cin >> val[i];

 dp[0] = 1;
 
    for(int j=0;j<n;j++){
      for(int i=1;i<=x;i++){
        if(i-val[j] >= 0)
        dp[i] = (dp[i] + dp[i-val[j]]) % mod;
      }
    }
  


  cout << dp[x] << "\n";

  

  return 0;
}