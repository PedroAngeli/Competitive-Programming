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

const int nax = 3e5 + 5;
vpii adj[nax];

struct Segtree{
  vi st;
  int n;
  vi a;
  void build(int l, int r,int pos){
    if(l == r){
      st[pos] = a[l];
      return;
    }
    int m = (l+r)/2;
    build(l, m, 2*pos+1);
    build(m+1, r, 2*pos+2);
    st[pos] = min(st[2*pos+1], st[2*pos+2]);
  }

  void build(vi& vet){
    n = sz(vet);
    a = vet;
    st.assign(4*n, INT_MAX);
    build(0, n-1, 0);
  }
  
  int query(int l,int r,int pos,int ql,int qr){
    if(ql > r or qr < l) return INT_MAX;
    if(ql <= l and r <= qr) return st[pos];
    int m = (l+r)/2;
    return min(query(l, m, 2*pos+1, ql, qr), query(m+1, r, 2*pos+2, ql, qr));
  }

  int query(int l,int r){
    return query(0, n-1, 0, l, r);
  }
};

struct Graph{
  vi subtree_sz, parent;
  vi pos; 
  vi head; 
  vi vet; 
  vi sobe;
  int idx = 0;
  Segtree st;
  
  void add_egde(int u,int v,int w){
    adj[u].pb({v,w});
    adj[v].pb({u,w});
  }

  void build_hld(int u,int p = -1,int ff = 1){
    pos[u] = idx++;
    vet[pos[u]] = sobe[u];
    subtree_sz[u] = 1;

    for(auto& e:adj[u]){
      int v = e.f;
      int w = e.s;
      if(v != p){
        parent[v] = u;
        sobe[v] = w;
        head[v] = (e == adj[u][0]) ? head[u] : v;
        build_hld(v,u,ff);
        subtree_sz[u] += subtree_sz[v];
         if(subtree_sz[v] > subtree_sz[adj[u][0].f] or adj[u][0].f == p) swap(e,adj[u][0]);
      }
    }

    if (p*ff == -1) 
      build_hld(head[u] = u, -1, idx = 0);
  }

  void build(int n, int root = 1){
    subtree_sz.resize(n+1);parent.resize(n+1);
    pos.resize(n+1);
    head.resize(n+1);
    vet.resize(n+1);
    sobe.resize(n+1);
    build_hld(root);
    st.build(vet);
  }

  int query_path(int u,int v){
    if(pos[u] > pos[v]) swap(u,v);

    if(head[u] == head[v])
      return st.query(pos[u] + 1, pos[v]);

    return min(st.query(pos[head[v]], pos[v]), query_path(parent[head[v]], u)); 
  }
};

int main(){
  fastio;
  
  int n, m;
  cin >> n >> m;
  Graph G;
  assert(m == n-1);
  for(int i=0;i<m;i++){
    int u, v, w;
    cin >> u >> v >> w;
    G.add_egde(u, v, w);
  }

  G.build(n);
  int q;
  cin >> q;

  while(q--){
    int u, v;
    cin >>u >> v;
    cout << G.query_path(u, v) << endl;
  }

  return 0;
}