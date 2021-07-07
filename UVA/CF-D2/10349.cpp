#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

vs grid;
int n,m;
int adj[400][400];
vi matchA;
vi matchB;
vector <bool> visB;

bool valid(int i,int j){
  return i >= 0 && i < n && j >= 0 && j < m;
}

bool dfs(int u){
  for(int v=0;v<400;v++){
    if(!adj[u][v] || visB[v])
      continue;
    visB[v] = true;
    if(matchB[v] == -1 || dfs(matchB[v])){
      matchA[u] = v;
      matchB[v] = u;
      return true;
    }
  }

  return false;
}

int kuhn(){
  int max_match = 0;
  matchA.assign(400,-1);
  matchB.assign(400,-1);
  bool flag = true;

  while(flag){
    flag = false;
    visB.assign(400,false);
    for(int i=0;i<400;i++){
      if(matchA[i] != -1)
        continue;
      if(dfs(i)){
        max_match++;
        flag = true;
      }
    }
  }

  return max_match;
}

int main(){
  fastio;

  int t;
  cin >> t;
  vpii mov = {{0,-1},{0,1},{1,0},{-1,0}};

  while(t--){
    cin >> n >> m;
    grid.resize(n);
    for(int i=0;i<400;i++)
      for(int j=0;j<400;j++)
        adj[i][j] = 0;
      
    for(int i=0;i<n;i++)
      cin >> grid[i];
    
    int ast = 0;

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(grid[i][j] == '*'){
          ast++;
          if((i+j)%2 == 0){
            int u = i*m + j;

            for(int k=0;k<4;k++){
              int x = i + mov[k].f;
              int y = j + mov[k].s;
              int v = x*m + y;
              if(valid(x,y) && grid[x][y] == '*')
                adj[u][v]++;
            }
          }
        }
      
      cout << ast - kuhn() << endl;
  }

  return 0;
}