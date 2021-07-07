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

struct Segtree{
  vll st, lazy;
  int n;
  void build(int _n){
    n = _n;
    st.assign(4*n,0);
    lazy.assign(4*n,0);
  }
  void propagate(int pos,int l,int r){
    if(lazy[pos] == 0)
      return;
    st[pos] += lazy[pos]*(r-l+1);
    if(l != r){
      lazy[2*pos+1] += lazy[pos];
      lazy[2*pos+2] += lazy[pos];
    } 
    lazy[pos] = 0;
  }

  void update(int l,int r,int pos,int ql,int qr,int val){
    propagate(pos,l,r);
    if(qr < l || ql > r)
      return;

    if(ql <= l && r <= qr){
      lazy[pos] += val;
      propagate(pos,l,r);
      return;
    }

    int m = (l+r)/2;
    update(l,m,2*pos+1,ql,qr,val);
    update(m+1,r,2*pos+2,ql,qr,val);
    st[pos] = st[2*pos+1] + st[2*pos+2];
  }

  void update(int l,int r,int val){
    update(0,n-1,0,l,r,val);
  }

  int query(int l,int r,int pos,int ql,int qr){
    propagate(pos,l,r);

    if(qr < l || ql > r)
      return 0;

    if(ql <= l && r <= qr)
      return st[pos];
    
    int m = (l+r)/2;
   return query(l,m,2*pos+1,ql,qr) + query(m+1,r,2*pos+2,ql,qr);
  }

  int query(int l,int r){
    return query(0,n-1,0,l,r);
  }
};

Segtree st;
vi pos,head,subtree_sz,parent;
vector <vi> adj;

namespace HLD{
  int idx;

  void add_egde(int u,int v){
    adj[u].pb(v);
    adj[v].pb(u);
  }

  void build_hld(int u,int p = -1,int ff = 1){
    pos[u] = idx++;
    subtree_sz[u] = 1;

    for(int& v:adj[u])
      if(v != p){
        parent[v] = u;
        head[v] = (v == adj[u][0]) ? head[u] : v;
        build_hld(v,u,ff);
        subtree_sz[u] += subtree_sz[v];
         if(subtree_sz[v] > subtree_sz[adj[u][0]] or adj[u][0] == p)
          swap(v,adj[u][0]);
      }

    if (p*ff == -1) 
      build_hld(head[u] = u, -1, idx = 0);
  }

  void build(int n,int root = 1){
    idx = 0;
    pos.resize(n+1);
    head.resize(n+1);
    subtree_sz.resize(n+1);
    parent.resize(n+1);
    build_hld(root);
    st.build(n);
  }

  int query_path(int u,int v){
    if(pos[u] > pos[v]) swap(u,v);

    if(head[u] == head[v])
      return st.query(pos[u], pos[v]);

    return st.query(pos[head[v]], pos[v]) + query_path(parent[head[v]], u);
  }

  void update_path(int u,int v,int val){
    if(pos[u] > pos[v]) swap(u,v);

    if(head[u] == head[v]){
      st.update(pos[u], pos[v], val);
      return;
    }

    st.update(pos[head[v]], pos[v], val);
    update_path(parent[head[v]], u, val);
  }
};

int main(){
  fastio;
  
  int n,q;
  cin >> n >> q;
  adj.resize(n+1);

  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    HLD :: add_egde(u,v);
  }

  HLD :: build(n);

  while(q--){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    HLD :: update_path(a,b,1);
    cout << HLD :: query_path(c,d) << endl;
    HLD :: update_path(a,b,-1);
  }
  return 0;
}