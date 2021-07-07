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

const int nax = 205;
vi vis;
vi adj[nax];
int V;

void dfs(int u){
  vis[u] = 1;
  V++;
  for(int v:adj[u]) 
    if(!vis[v])
      dfs(v);
}
int main(){
  fastio;

  int n,m;
  while(cin >> n >> m){
    vi degree(n, 0);
    for(int i=0;i<n;i++) adj[i].clear();
    vis.assign(n, 0);
    V = 0;
    if(m == 0){
      cout << "Not Possible" << endl;
      continue;
    }
    while(m--){
      int u,v;
      cin >> u >> v;
      degree[u]++;
      degree[v]++;
      adj[u].pb(v);
      adj[v].pb(u);
    }

    bool can = true;
    for(int i=0;i<n;i++)
      can = (can and (degree[i]%2 == 0));

    for(int i=0;i<n;i++)
      if(degree[i]){
        dfs(i);
        break;
      }

    for(int i=0;i<n;i++)
      if(degree[i] and !vis[i])
        can = false;
    if(can) cout << "Possible" << endl;
    else cout << "Not Possible" << endl;
  }
  return 0;
}