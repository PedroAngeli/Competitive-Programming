#include <bits/stdc++.h>

using namespace std;

int H,W;
const int MAXN = 1e3 + 5;
const int mod = 1e9 + 7;
vector <string> grid;
int dp[MAXN][MAXN]; //guarda quantos caminhos existem até (H-1,W-1) partindo de (i,j)

bool valid(int i,int j){
  return i >= 0 && i < H && j>=0 && j < W && grid[i][j] != '#';
}

bool destiny(int i,int j){
  return i == H-1 && j == W-1;
}

int solve(int i,int j){

  if(destiny(i,j)){
    return 1;
  }

  if(dp[i][j] != -1){
    return dp[i][j];
  }

  int r = 0;
  int d = 0;

  if(valid(i+1,j)){
    d = solve(i+1,j)%mod;
  }

  if(valid(i,j+1)){
    r = solve(i,j+1)%mod;
  }

  return dp[i][j] = (r + d)%mod;
}

int main(){
  cin >> H >> W;

  int h = H;

  while(h--){
    string line;
    cin >> line;
    grid.push_back(line);
  }

   memset(dp,-1,sizeof dp);

  cout << solve(0,0) << endl;
}