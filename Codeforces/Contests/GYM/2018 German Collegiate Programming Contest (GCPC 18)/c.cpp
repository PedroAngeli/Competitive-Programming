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

const int nax = 1005;
int adj[nax][nax];
vi topo;
vi vis;
int n,m;

void solve(int u){
  vis[u] = 1;
  for(int v=1;v<=n;v++)
    if(adj[u][v] && !vis[v])
      solve(v);

  topo.pb(u);
}

int main(){
  fastio;

  cin >> n >> m;

  vis.assign(n+1,0);

  for(int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u][v] = max(adj[u][v], w);
  }

  for(int i=1;i<=n;i++)
    if(!vis[i])
      solve(i);

  reverse(all(topo));

  vi dist(n+1,0);

  for(int u : topo){
    for(int v=1;v<=n;v++){
      if(adj[u][v])
        dist[v] = max(dist[v], dist[u] + adj[u][v]);
    }
  }
    

  int ans = 0;
  for(int i=1;i<=n;i++){
    ans = max(dist[i],ans);
  }

  cout << ans << endl;
  return 0;
}