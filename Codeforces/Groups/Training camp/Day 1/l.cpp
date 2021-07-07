#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int n;
const int nax = 305;
vector <vector <int> > grid;
int dp[nax][nax][nax];
const int INF = 1e9 + 7;

int solve(int x1,int y1,int x2){
  int y2 = x1+y1 - x2;

  if(x1 == n || y1==n || x2 == n || y2 == n)
    return -INF;

  if(x1 == n-1 && y1 == n-1 && x2 == n-1 && y2 == n-1)
    return grid[n-1][n-1];

  int& state = dp[x1][y1][x2];

  if(state != -1)
    return state;

  int val = grid[x1][y1];

  if(x1 != x2)
    val += grid[x2][y2];

  return state = val + max({solve(x1+1,y1,x2),solve(x1+1,y1,x2+1),solve(x1,y1+1,x2),solve(x1,y1+1,x2+1)});
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  cin >> n;
  grid.assign(n,vector <int>(n));
  memset(dp,-1,sizeof dp);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin >> grid[i][j];
 
  cout << solve(0,0,0) << endl;

  return 0;
}