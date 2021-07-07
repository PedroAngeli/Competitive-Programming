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

const int nax = 2e4 + 5;
const int INF = 1e9 + 7;

int vet[nax];

namespace Segtree{
  int n;
  vi st;
  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = vet[l];
      return;
    }
    int m = (l+r)/2;
    build(l,m,2*pos+1);
    build(m+1,r,2*pos+2);
    st[pos] = min(st[2*pos+1], st[2*pos+2]);
  }
  void build(int _n){
    n = _n;
    st.assign(4*n, INF);
    build(0,n-1,0);
  }
  int query(int l,int r,int pos,int ql,int qr){
    if(l > qr || r < ql) return INF;
    if(ql <= l && r <= qr) return st[pos];
    int m = (l+r)/2;
    return min(query(l,m,2*pos+1,ql,qr), query(m+1,r,2*pos+2,ql,qr));
  }
  int query(int l,int r){
    return query(0,n-1,0,l,r);
  }
};

namespace HLD{
  vpii adj[nax];
  int subtree_sz[nax], parent[nax];
  int pos[nax]; //position of vertice in the array vet 
  int head[nax]; //head of chain
  int sobe[nax]; //peso da aresta entre u e parent[u]
  int idx;
  
  void clear(int n){
    for(int i=1;i<=n;i++)
      adj[i].clear();
  }
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

  void build(int root = 1){
    idx = 0;
    build_hld(root);
    Segtree :: build(idx); //build segtree with array vet
  }

  int query_path(int u,int v){
    if(pos[u] > pos[v]) swap(u,v);

    if(head[u] == head[v])
      return Segtree :: query(pos[u] + 1, pos[v]);

    return min(Segtree :: query(pos[head[v]], pos[v]), query_path(parent[head[v]], u)); //minimun query 
  }
};

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
  bool join(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)
      return false;
    if(set_size[x] > set_size[y])
      swap(x,y);
    parent[x] = y;
    set_size[y] += set_size[x];
    return true;
  }
};

int main(){
  fastio;

  int n,m,q;
  while(cin >> n >> m >> q){
    HLD :: clear(n);
      vector <pair <int,pii> > edges;

    for(int i=0;i<m;i++){
      int u,v,w;
      cin >> u >> v >> w;
      edges.pb({w,{u,v}});
    }

    sort(all(edges));
    reverse(all(edges));

    UnionFind dsu(n);

    for(auto e:edges){
      int w = e.f;
      int u = e.s.f;
      int v = e.s.s;
      if(dsu.join(u,v)) HLD :: add_egde(u,v,w);
    }

    HLD :: build();

    while(q--){
      int u,v;
      cin >> u >> v;
      cout << HLD :: query_path(u,v) << endl;
    }
  }
  
  
  
  return 0;
}