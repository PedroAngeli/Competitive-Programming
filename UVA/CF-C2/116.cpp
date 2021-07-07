#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

vector <vector <int> > grid;
vector <vector <int> > dp;
int n,m;
vector <vector<pair <int,int> > > parent;

int mod(int x){
  return (x%n + n)%n;
}

int solve(int i,int j){
  if(j == m){
    return 0;
  }

  if(dp[i][j] != -1)
    return dp[i][j];

  int mn = INT_MAX;

  int nextA = mod(i);
  int a = solve(nextA,j+1);
  mn = a;
  parent[i][j] = {nextA,j+1};

  int nextB = mod(i+1);
  int b = solve(nextB,j+1);
  if(b < mn){
    mn = b;
    parent[i][j] = {nextB,j+1};
  }else if(b == mn){
    parent[i][j] = {min(parent[i][j].first,nextB),j+1};
  }

  int nextC = mod(i-1);
  int c = solve(nextC,j+1);
  if(c < mn){
    mn = c;
    parent[i][j] = {nextC,j+1};
  }else if(c == mn){
    parent[i][j] = {min(parent[i][j].first,nextC),j+1};
  }
  
  return dp[i][j] = grid[i][j] + mn;
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 

  while(cin >> n >> m){
    grid.assign(n,vector <int>(m));
    dp.assign(n,vector <int>(m,-1));
    parent.assign(n,vector <pair<int,int> >(m));

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin >> grid[i][j];

    pair <int,int> curPos;
    int mn = INT_MAX;

    for(int i=0;i<n;i++){
      int curPath = solve(i,0);
      if(curPath < mn){
        curPos = {i,0};
        mn = curPath;
      }
    }

    for(int i=0;i<m;i++){
      int x = curPos.first;
      int y = curPos.second;

      if(i == m-1)
        cout << x+1 << endl;
      else
        cout << x+1 << " ";

      curPos = parent[x][y];
    }

    cout << mn << endl;
  }
  return 0;
}