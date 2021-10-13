#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
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

struct UnionFind{
  vi parent;
  vi set_size;
  int n;
  UnionFind(int n):n(n){
    parent.resize(n+1);
    iota(all(parent),0);
    set_size.assign(n+1,1);
  }
  int find(int x){
    if(x == parent[x])
      return x;
    return parent[x] = find(parent[x]);
  }
  void join(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)
      return;
    if(set_size[x] > set_size[y])
      swap(x,y);
    parent[x] = y;
    set_size[y] += set_size[x];
  }
};
  const ll INF = 1e18 + 7;

struct Graph{
  vector <pair <int, pii> > edges;
  vector <pair <int, pii> > edges_in_mst;

  int V;
  
  Graph(int V): V(V){}

  void addEdge(int u,int v,int w){
    edges.pb({w,{u,v}});
  }

  ll kruskal(){ //Returns the cost of the MST. O(E LOG E)
    sort(all(edges));
    UnionFind dsu(V);
    ll cost = 0;

    for(auto e : edges){
      int w = e.f;
      int u = e.s.f;
      int v = e.s.s;
      if(dsu.find(u) == dsu.find(v))
        continue;
      edges_in_mst.pb({w,{u,v}});
      dsu.join(u,v);
      cost += w;
    }
    if(edges_in_mst.size() < V-1) return -INF;
    return cost;
  }

};

int main(){
  fastio;

  int n, m;
  cin >> n >> m;

  Graph G(n);

  for(int i=0;i<m;i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    G.addEdge(a, b, c);
  }

  ll ans = G.kruskal();
  if(ans == -INF) cout << "IMPOSSIBLE" <<endl;
  else cout << ans <<endl;
  return 0;
}