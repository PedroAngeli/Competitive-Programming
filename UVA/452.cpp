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

vector <char> adj[26];
int in_deg[26];
int spend[26];
vi topo;
vi vis;

void dfs(int u){
  vis[u] = 1;
  for(auto v:adj[u]){
    if(!vis[v-'A']) dfs(v-'A');
  }
  topo.pb(u);
}
int main(){
  fastio;

  int t;
  cin >> t;
  string line;
  getline(cin, line);
  getline(cin, line);
  int ncase = 0;
  while(t--){
    if(ncase) cout << endl;
    ncase++;
    topo.clear();
    vis.assign(27, 0);
    for(int i=0;i<26;i++) adj[i].clear(), in_deg[i] = 0, spend[i] = 0;
    while(getline(cin, line)){
      if(sz(line) == 0) break;
      stringstream ss(line);
      char u;
      string S;
      int T;
      ss >> u >> T >> S;
      spend[u-'A'] = T;
      for(auto c:S){
        adj[c-'A'].pb(u);
        in_deg[u-'A']++;
      } 
    }

    for(int i=0;i<26;i++) if(!vis[i]) dfs(i);

    int ans = 0;
    vi dist(26, 0);
    for(auto u:topo){
      for(auto v:adj[u])
        dist[u] = max(dist[u], spend[v-'A'] + dist[v-'A']);
    }

    for(int i=0;i<26;i++) ans = max(ans, dist[i] + spend[i]);
    cout << ans << endl;
  }
  return 0;
}