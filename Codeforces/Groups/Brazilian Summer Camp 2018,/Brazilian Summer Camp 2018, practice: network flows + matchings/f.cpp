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
vi match;
vi vis;
int n, m;
 
bool dfs(int u){
  vis[u] = 1;
  for(int v:adj[u]){
    if(match[v] == -1 || (!vis[match[v]] && dfs(match[v]))){
      match[v] = u;
      return true;
    }
  }
  return false;
}

int solve(){
  match.assign(n,-1);
  bool flag = true;
  int max_match = 0;
 
  for(int i=0;i<n;i++){
    vis.assign(n,0);
    if(dfs(i)){
        max_match++;
      }
  }
 
  return max_match;
}

vi topo;

void find_topo(int u){
  vis[u] = 1;
  for(int v:adj[u])
    if(!vis[v]) find_topo(v);
  topo.pb(u);
}

int main(){
  fastio;

  cin >> n >> m;
  
  for(int i=0;i<m;i++){
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
  }

  int ans = n - solve();
  cout << ans << endl;

  vis.assign(n, 0);
  for(int i=0;i<n;i++)
    if(!vis[i])
      find_topo(i);
  
  vis.assign(n, 0);
  vector <vi> paths;
  for(int u:topo){
    if(vis[u]) continue;
    vi p;
    while(true){
      vis[u] = 1;
      p.pb(u);
      if(match[u] == -1) break;
      u = match[u];
    }
    reverse(all(p));
    paths.pb(p);
  }
  assert(ans == paths.size());

  for(auto v:paths){
    for(int x:v)
      cout << x+1 <<" ";
    cout << endl;
  }

  

  return 0;
}