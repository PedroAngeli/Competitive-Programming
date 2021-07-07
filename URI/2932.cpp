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

const ll INF = 1e18;
const int nax = 2e5 + 5;
int n;
int has[nax], is_sick[nax];
vpii adj[nax];
ll dp[nax][2];

void solve(int u,int p=-1){
  if(is_sick[u]) dp[u][0] = INF;

  vpii child_sick;

  for(auto el:adj[u]){
    int v = el.f;
    ll w = el.s;
    if(v == p) continue;
    solve(v, u);
    if(!is_sick[u]){
      if(has[v]){
         child_sick.pb(el);
         dp[u][0] += min(dp[v][0], w);
      }
    }else{
      if(has[v]) dp[u][1] += min(dp[v][0], w);
    }
    has[u] = (has[u] or has[v]);
  }

  if(is_sick[u] or sz(child_sick) == 0) return;

  vll tmp, pref(sz(child_sick)), suf(sz(child_sick));

  for(auto el:child_sick) 
    tmp.pb(min((ll)el.s, dp[el.f][0]));

  for(int i=0;i<sz(child_sick);i++){
    pref[i] = tmp[i];
    if(i > 0) pref[i] += pref[i-1];
  }

  for(int i=sz(child_sick)-1;i>=0;i--){
    suf[i] = tmp[i];
    if(i + 1 < sz(child_sick)) suf[i] += suf[i+1];
  }

  ll mn = INF;

  for(int i=0;i<sz(child_sick);i++){
    int v = child_sick[i].f;
    ll cost = dp[v][1];
    if(i > 0) cost += pref[i-1];
    if(i + 1 < sz(child_sick)) cost += suf[i+1];
    mn = min(mn, cost);
  }
  
  dp[u][1] = mn;
}

int main(){
  fastio;

  int m;
  cin >> n >> m;

  for(int i=0;i<m;i++){
    int x;
    cin >> x;
    has[x] = is_sick[x] = 1;
  }

  for(int i=0;i<n-1;i++){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].pb({v, w});
    adj[v].pb({u, w});
  }
  
  solve(0);
  
  for(int i=0;i<n;i++)
    debug(i, dp[i][0], dp[i][1]);

  return 0;
}