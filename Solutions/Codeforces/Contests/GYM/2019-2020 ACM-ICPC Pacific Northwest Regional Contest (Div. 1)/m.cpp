#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << "[" << name << " : " << arg1 << "]" << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cerr << "[";
cerr.write(names, comma - names) << " : " << arg1<<"] | ";__f(comma+1, args...);
}

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

int n,m;
bool vis[1005][1005];
vs grid;

bool valid(int i,int j){
  return i>=0 && i<=(n+1) && j>=0 && j<=(m+1) && !vis[i][j];
}
void dfs(int i,int j){
  if(!valid(i,j) || (grid[i][j] != '.'))
    return;
  vis[i][j] = true;
  dfs(i+1,j);
  dfs(i-1,j);
  dfs(i,j-1);
  dfs(i,j+1);
  if(valid(i-1,j) && grid[i-1][j] != '\\')
    dfs(i-1,j+1);
  if(valid(i,j-1) && grid[i][j-1] != '\\')
    dfs(i+1,j-1);
  if(valid(i-1,j) && grid[i-1][j] != '/')
    dfs(i-1,j-1);
  if(valid(i,j+1) && grid[i][j+1] != '/')
    dfs(i+1,j+1);
}

int main(){
  fastio;

  cin >> n >> m;

  grid.assign(n+4,string(m+4,'.'));

  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin >>grid[i][j];
      
  int ans = 0;

  for(int i=0;i<=n+1;i++)
    for(int j=0;j<=m+1;j++)
      if(grid[i][j] == '.' && !vis[i][j]){
        dfs(i,j);
        ans++;
      }

  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(grid[i][j] == '/' && grid[i+1][j+1] == '/' && grid[i+1][j] == '\\' && grid[i][j+1] == '\\')
        ans++;

  cout << ans-1 << endl;

  return 0;
}