#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n;
const int nax = 1e5 + 5;
int dp[nax][3];
vector <int> h;
vector <int> p;

int solve(int i, int last){
  int cut_l = 0,cut_r = 0,no_cut = 0;

  if(i == n-1)
    return 1;

  if(dp[i][last] != -1)
    return dp[i][last];

  if(last == 0 || last == 1){
    if(p[i]-h[i] > p[i-1])
      cut_l = 1 + solve(i+1,1);

    if(p[i]+h[i] < p[i+1])
      cut_r = 1 + solve(i+1,2);
  }

  if(last == 2){
    if(p[i]-h[i] > p[i-1]+h[i-1])
      cut_l = 1 + solve(i+1,1);

    if(p[i]+h[i] < p[i+1])
      cut_r = 1 + solve(i+1,2);
  }

  no_cut = solve(i+1,0);


  return dp[i][last] = max({cut_l,cut_r,no_cut});
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  h.resize(n);
  p.resize(n);

  for(int i=0;i<n;i++)
    cin >> p[i] >> h[i];

  memset(dp,-1,sizeof dp);

  int ans = 0;
  if(n > 1)
    ans = solve(1,1);

  cout << ans + 1 << endl;

  return 0;
}