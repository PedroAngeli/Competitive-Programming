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

const int nax = 1e5 + 5;
int mod;
vi adj[nax];
vi child[nax], pref[nax], suf[nax];
int dp[nax][2];
int ans[nax], up[nax];

int add(int a, int b){
  return (a + b)%mod;
}

int mul(int a, int b){
  return ((ll)a*b)%mod;
}

int sub(int a,int b){
  return ((a-b)%mod + mod)%mod;
}

void dfs(int u,int p=-1){  
  int pos = -1;
  for(int i=0;i<sz(adj[u]);i++) if(adj[u][i] == p) pos = i;
  if(pos != -1) adj[u].erase(adj[u].begin() + pos);
  
  int len = sz(adj[u]);
  child[u].assign(len, 1);
  pref[u].assign(len, 1);
  suf[u].assign(len, 1);

  dp[u][0] = dp[u][1] = 1;

  for(int i=0;i<len;i++){
    int v = adj[u][i];
    dfs(v, u);
    dp[u][1] = mul(dp[u][1], add(dp[v][1], dp[v][0]));
    dp[u][0] = mul(dp[u][0], dp[v][0]);
    child[u][i] = add(dp[v][1], dp[v][0]);
  }

  for(int i=0;i<len;i++){
    pref[u][i] = child[u][i];
    if(i > 0) pref[u][i] = mul(pref[u][i], pref[u][i-1]); 
  }

  for(int i=len-1;i>=0;i--){
    suf[u][i] = child[u][i];
    if(i + 1 < len) suf[u][i] = mul(suf[u][i], suf[u][i+1]);
  }
}

void reroot(int u, int i=-1, int p=-1){
  if(p == -1) ans[u] = dp[u][1], up[u] = 1;
  else{
    up[u] = up[p];
    if(i > 0) up[u] = mul(up[u], pref[p][i-1]);
    if(i + 1 < sz(suf[p])) up[u] = mul(up[u], suf[p][i+1]);
    up[u] = add(1, up[u]);
    ans[u] = mul(up[u], dp[u][1]);
  }

  int len = sz(adj[u]);
  for(int i=0;i<len;i++){
    int v = adj[u][i];
    reroot(v, i, u);
  }
}

int main(){
  fastio;

  int n;
  cin >> n >> mod;

  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs(1);
  reroot(1);

  for(int i=1;i<=n;i++)
    cout << ans[i] << endl;

  return 0;
}