#include <bits/stdc++.h>

using namespace std;

const int xax = 1e5 + 5;

int dp[xax];

int main(){

  int n, x;
  cin >> n >> x;

  vector <int> prices(n);
  vector <int> pages(n);

  for(int i=0;i<n;i++)
    cin >> prices[i];

  for(int i=0;i<n;i++)
    cin >> pages[i];

  for(int i=0;i<n;i++){
    for(int j=x;j>=1;j--){
      if(j-prices[i] >= 0){
        dp[j] = max(dp[j], pages[i] + dp[j-prices[i]]);
      }
    }
  }

  cout << dp[x] << endl;

  return 0;
}