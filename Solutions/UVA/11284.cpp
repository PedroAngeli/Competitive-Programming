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

const ld EPS = 1e-9;

bool lte(ld x,ld y){ //x <= y
  return x < y + EPS;
}

bool gt(ld x,ld y){ //x > y
  return !lte(x, y);
}

struct Graph{
  vector <vector <pair <int,ld> > > adj; 
  int V;
  const int INF = 1e9 + 7;
  
  Graph(int V): V(V){
    adj.resize(V+1);
  }

  void addEdge(int u,int v,ld w){
    adj[u].pb({v,w});
    adj[v].pb({u,w}); 
  }

  vector <ld> dijkstra(int source){ 
    vector <ld> dist(V+1,INF);
    dist[source] = 0;

    set <pair <ld,int> > pq;
    pq.insert({0,source});
    
    while(!pq.empty()){
      auto it = pq.begin();
      ld d = it->f;
      int u = it->s;
      pq.erase(it);

      if(gt(d, dist[u]))
        continue;

      for(auto el : adj[u]){
        int v = el.f;
        ld w = el.s;
        if(gt(dist[v], dist[u] + w)){
          dist[v] = dist[u] + w;
          pq.insert({dist[v], v});
        }
      }
    }

    return dist;
  }
};

int p;
vector <vector <ld> > dp;
vector <ld> store_cost;
ld cost;

ld solve(int u,int mask,Graph& G){
  if(u == 0 and mask){
    ld sum = 0;
    for(int i=0;i<p;i++)
      if(mask & (1 << i)) sum += store_cost[i];
    return cost - sum;
  }

  ld& state = dp[u][mask];
  if(state > -0.5) return state;

  state = DBL_MAX;

  for(auto el:G.adj[u]){
    int v = el.f;
    ld w = el.s;
    if((mask & (1 << v)) == 0)
      state = min(state, w + solve(v, mask | (1 << v), G));
  }
    
  return state;
}

int main(){
  fastio;

  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    Graph g1(n);

    for(int i=0;i<m;i++){
      int u,v;
      ld w;
      cin >> u >> v >> w;
      g1.addEdge(u, v, w);
    }

    cin >> p;

    vi stores(p+1);
    stores[0] = 0;
    store_cost.assign(p+1, 0);
    cost = 0;
    for(int i=1;i<=p;i++){
      cin >> stores[i] >> store_cost[i];
      cost += store_cost[i];
    }

    Graph g2(n);

    for(int i=0;i<=p;i++){
      vector <ld> dist = g1.dijkstra(stores[i]);
      for(int j=0;j<=p;j++)
        if(i != j){
          g2.addEdge(i, j, dist[stores[j]]);
        }
    }

    cout << fixed << setprecision(2);
    p++;
    dp.assign(p, vector <ld> ((1 << p), -1));
    ld tsp = solve(0, 0, g2);
    ld save = cost - tsp;
    if(lte(save, 0)) cout << "Don't leave the house" << endl;
    else cout << "Daniel can save $" << save << endl;
  }
  return 0;
}