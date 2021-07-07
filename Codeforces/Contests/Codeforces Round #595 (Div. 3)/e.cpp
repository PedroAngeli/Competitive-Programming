#include <bits/stdc++.h>

using namespace std;


int main(){

  int n,c;

  cin >> n >> c;

  vector <int> s(n+1);
  vector <int> e(n+1);
  int dp[n+1][2]; //dp[i] guarda a menor distancia para chegar no andar i. 
  //[0] - escada
  //[1] - elevador

  for(int i=1;i<n;i++)
    cin >> s[i];

  for(int i=1;i<n;i++)
    cin >> e[i];

  dp[0][0] = 0;
  dp[0][1] = c;

  cout << "0 ";

  for(int i=1;i<n;i++){
    dp[i][0] = min(dp[i-1][0] + s[i],dp[i-1][1] + s[i]); 
    dp[i][1] = min(dp[i-1][0] + e[i] + c, dp[i-1][1] + e[i]);
    cout << min(dp[i][0],dp[i][1]) << " ";
  }

  cout << endl;

  

  
  return 0;
}