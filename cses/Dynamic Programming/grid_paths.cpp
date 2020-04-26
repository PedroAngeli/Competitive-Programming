#include <bits/stdc++.h>

using namespace std;

int n;
vector <string> grid;
const int mod = 1e9 + 7;
const int nax = 1e3 + 5;
int dp[nax][nax];

bool valid(int i,int j){
  return i >= 0 && i < n && j>=0 && j < n && grid[i][j] != '*';
}

int solve(int i, int j){

  if(!valid(i,j))
    return 0;

  if(i == n-1 && j == n-1)
    return 1;

  if(dp[i][j] != -1)
    return dp[i][j];
  
  int d = 0;
  int r = 0;

  if(valid(i+1,j)){
    d = solve(i+1,j);
  }

  if(valid(i,j+1)){
    r = solve(i,j+1);
  }

  return dp[i][j] = (d+r)%mod;
}

int main(){

 cin >> n;

 for(int i=0;i<n;i++){
   string temp;
   cin >> temp;
   grid.push_back(temp);
 }

 memset(dp, -1, sizeof dp);

 cout << solve(0,0) << endl;
  

  return 0;
}