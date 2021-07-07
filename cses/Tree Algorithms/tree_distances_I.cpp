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

const int nax = 2e5 + 5;
int n;
vi adj[nax], pref[nax], suf[nax], child_dp[nax];
int ans[nax], down_path[nax], pa[nax], par[nax];

void dfs(int u,int p=-1){
  par[u] = p; 
  pref[u].resize(sz(adj[u]));
  suf[u].resize(sz(adj[u]));
  child_dp[u].resize(sz(adj[u]));

  int pos = -1;
  for(int i=0;i<sz(adj[u]);i++) if(p == adj[u][i]) pos = i;
  if(pos != -1) adj[u].erase(adj[u].begin() + pos);

  for(int i=0;i<sz(adj[u]);i++){
    int v = adj[u][i];
    dfs(v, u);
    down_path[u] = max(down_path[u], 1 + down_path[v]);
    child_dp[u][i] = down_path[v] + 1;
  }

  for(int i=0;i<sz(adj[u]);i++){
    pref[u][i] = child_dp[u][i];
    if(i > 0) pref[u][i] = max(pref[u][i], pref[u][i-1]);
  }

  for(int i=sz(adj[u])-1;i>=0;i--){
    suf[u][i] = child_dp[u][i];
    if(i + 1 < sz(adj[u])) suf[u][i] = max(suf[u][i], suf[u][i+1]);
  }
}

void dfs2(int u,int i=-1){
  int p = par[u];
  if(p == -1) ans[u] = down_path[u];
  else{
    if(i + 1 < sz(adj[p])) pa[u] = max(pa[u], 1 + suf[p][i+1]);
    if(i > 0) pa[u] = max(pa[u], 1 + pref[p][i-1]);
    pa[u] = max(pa[u], 1 + pa[p]);
    ans[u] = max(down_path[u], pa[u]);
  }

  for(int j=0;j<sz(adj[u]);j++){
    int v = adj[u][j];
    dfs2(v, j);
  }
}

int main(){
  fastio;

  cin >> n;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfs(1);
  dfs2(1);

  for(int i=1;i<=n;i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}