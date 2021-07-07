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

vi adj[25];
int n,m;

vector <vi> find_tree(pii p){
  int source = p.f;
  vector <vi> tree(n);
  vi vis(n,0);
  vis[source] = 1;
  queue <int> q;
  q.push(source);
  if(p.s != -1){
    q.push(p.s);
    vis[p.s] = 1;
    tree[source].pb(p.s);
    tree[p.s].pb(source);
  }

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v:adj[u]){
      if(vis[v]) continue;
      q.push(v);
      vis[v] = 1;
      tree[u].pb(v);
      tree[v].pb(u);
    }
  }

  return tree;
}

vi dist;

int bfs(int source, vector <vi>& tree){
  dist.assign(n,INT_MAX);
  dist[source] = 0;
  queue <int> q;
  q.push(source);

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v:tree[u]){
      if(dist[v] < INT_MAX) continue;
      q.push(v);
      dist[v] = dist[u] + 1;
    }
  }

  int d = 0;
  int v = 0;
  for(int i=0;i<n;i++){
    if(dist[i] > d){
      d = dist[i];
      v = i;
    }
  }
    
    return v;
}

int diameter(vector <vi>& tree){
  int v = bfs(bfs(0,tree),tree);
  return dist[v];
}

int main(){
  fastio;

  int t;
  cin >> t;
  int ncase = 0;
  while(t--){
    ncase++;
    cin >> n >> m;
    for(int i=0;i<n;i++) adj[i].clear();
    vpii edges;
    while(m--){
      int u,v;
      cin >>u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
      edges.pb({u,v});
    }
    
    int ans = INT_MAX;

    for(int i=0;i<n;i++){
      pii p = {i,-1};
      vector <vi> tree = find_tree(p);
      ans = min(ans, diameter(tree));
    }

    for(int i=0;i<sz(edges);i++){
      pii p = edges[i];
      vector <vi> tree = find_tree(p);
      ans = min(ans, diameter(tree));
    }

    cout << "Case #" << ncase << ":" << endl;
    cout << ans << endl;
    cout << endl;
  }
  return 0;
}