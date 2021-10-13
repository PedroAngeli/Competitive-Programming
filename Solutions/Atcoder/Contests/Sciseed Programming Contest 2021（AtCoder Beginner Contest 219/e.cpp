#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ld = long double;
using ll = long long;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
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

const int nax = 4;
int pol[nax][nax];
int mat[nax][nax];
bool vis[nax][nax];


bool inside_limit(int i, int j){
  return i >= 0 and i < nax and j >= 0 and j < nax;
}
bool valid_one(int i,int j){
  return inside_limit(i, j) and pol[i][j] == 1 and vis[i][j] == false;
}

bool valid_zero(int i,int j){
  return inside_limit(i, j) and pol[i][j] == 0 and vis[i][j] == false;
}

void dfs(int i,int j){
  if(!valid_one(i, j)) return;
  vis[i][j] = true;
  dfs(i+1, j);
  dfs(i-1, j);
  dfs(i, j+1);
  dfs(i, j-1);
}

void dfs_2(int i, int j){
  if(!valid_zero(i, j)) return;
  vis[i][j] = true;
  dfs_2(i+1, j);
  dfs_2(i-1, j);
  dfs_2(i, j+1);
  dfs_2(i, j-1);
}

int main(){
  fastio;

  for(int i=0;i<nax;i++)
    for(int j=0;j<nax;j++)
      cin >> mat[i][j];

  int ans = 0;

  for(int mask=0;mask<(1 << nax*nax);mask++){
    int k = 0, l = 0;

    for(int i=0;i<nax*nax;i++){
      pol[k][l] = ((mask & (1 << i)) > 0); 
      l++;
      if(l == 4){
        k++;
        l = 0;
      }
    }

    memset(vis, false, sizeof vis);
    int cnt = 0;
    for(int i=0;i<nax;i++)
      for(int j=0;j<nax;j++)
        if(pol[i][j] == 1 and !vis[i][j])
          cnt++, dfs(i, j);

    if(cnt != 1) continue;
    bool can = true;
    
    for(int i=0;i<nax;i++)
      if(pol[i][0] == 0 and !vis[i][0])
        dfs_2(i, 0);
    
    for(int i=0;i<nax;i++)
      if(pol[i][nax-1] == 0 and !vis[i][nax-1])
        dfs_2(i, nax-1);

    for(int j=0;j<nax;j++)
      if(pol[0][j] == 0 and !vis[0][j])
        dfs_2(0, j);

    for(int j=0;j<nax;j++)
      if(pol[nax-1][j] == 0 and !vis[nax-1][j])
        dfs_2(nax-1, j);

    for(int i=0;i<nax;i++)
      for(int j=0;j<nax;j++)
        if(vis[i][j] == false)
          can = false;

    for(int i=0;i<nax;i++)
      for(int j=0;j<nax;j++)
        if(mat[i][j] and !pol[i][j])
          can = false;

    if(can)
      ans++;
  }
  
  
  cout << ans << endl;
  return 0;
}