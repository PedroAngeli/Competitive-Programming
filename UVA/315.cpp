#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fbo find_by_order 
#define ook order_of_key 
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

const int nax = 105;
vi adj[nax];
int dfs_num[nax], dfs_low[nax], is_art[nax], parent[nax];
int n;
int dfs_cnt, root_children;

void dfs(int u){
  dfs_low[u] = dfs_num[u] = dfs_cnt++;
  for(int v:adj[u]){
    if(dfs_num[v] == -1){
      if(u == 1) root_children++;
      parent[v] = u;
      dfs(v);
      if(dfs_low[v] >= dfs_num[u]) is_art[u] = 1;
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }else if(v != parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

int main(){
  fastio;

  while(cin >> n and n){
    string line;
    for(int i=1;i<=n;i++) adj[i].clear();
    memset(dfs_num, -1, sizeof dfs_num);
    memset(dfs_low, -1, sizeof dfs_low);
    memset(is_art, 0, sizeof is_art);
    memset(parent, 0, sizeof parent);
    dfs_cnt = 0;
    root_children = 0;

    getline(cin, line);
    while(getline(cin, line) and line[0] != '0'){
      stringstream ss(line);
      int u, v;
      ss >> u;

      while(ss >> v){
        adj[u].pb(v);
        adj[v].pb(u);
      }
    }

    dfs(1);
    is_art[1] = (root_children > 1);
    int ans = 0;
    for(int i=1;i<=n;i++){
      ans += is_art[i];
    } 
    cout << ans << endl;
  } 

  return 0;
}