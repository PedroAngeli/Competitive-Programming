#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

const int nax = 45;
int dp[nax][nax][nax][nax];
int sum[nax][nax];
char grid[nax][nax];

int main(){
  fastio;

  int n, m, q;
  cin >> n >> m >> q;

  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin >> grid[i][j];
  
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (grid[i][j]-'0');
  
  for(int a=n;a>=1;a--)
    for(int b=m;b>=1;b--)
      for(int c=a;c<=n;c++)
        for(int d=b;d<=m;d++){
          int& state = dp[a][b][c][d];
          state += (sum[c][d] - sum[a-1][d] - sum[c][b-1] + sum[a-1][b-1] == 0);
          state += (dp[a+1][b][c][d] + dp[a][b+1][c][d] + dp[a][b][c-1][d] + dp[a][b][c][d-1]);
          state -= (dp[a+1][b+1][c][d] + dp[a+1][b][c-1][d] + dp[a][b+1][c-1][d] + dp[a+1][b][c][d-1] + dp[a][b+1][c][d-1] + dp[a][b][c-1][d-1]);
          state += (dp[a+1][b+1][c-1][d] + dp[a+1][b+1][c][d-1] + dp[a+1][b][c-1][d-1] + dp[a][b+1][c-1][d-1]);
          state -= (dp[a+1][b+1][c-1][d-1]);
        }

  while(q--){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << dp[a][b][c][d] << endl;
  }
  return 0;
}