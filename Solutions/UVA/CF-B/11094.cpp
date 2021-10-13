#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,m;
vector <string> grid;
char land;
bool visitado[25][25];

bool valid(int i,int j){
  return  i >=0 && i < n && j>=0 && j < m && grid[i][j] == land && !visitado[i][j];
}

int mod(int j){
  return ((j%m)+m)%m;
}

int solve(int i,int j){
  if(!valid(i,j))
    return 0;

  visitado[i][j] = true;

  return 1 + solve(i+1,mod(j)) + solve(i-1,mod(j)) + solve(i,mod(j+1)) + solve(i,mod(j-1));
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while(cin >> n >> m){
    grid.resize(n);
    memset(visitado, false, sizeof visitado);

    for(int i=0;i<n;i++)  
      cin >> grid[i];

    int x,y;
    cin >> x >> y;

    land = grid[x][y];

    solve(x,y);

    int ans = 0;

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        ans = max(ans,solve(i,j));

    cout << ans << endl;
  }  
  
  return 0;
}