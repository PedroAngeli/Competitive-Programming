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

const int nax = 2e5 + 5;
int n,q;
vi val;
vi adj[nax];

struct Segtree{
  vll st;
  vi a;
  int n;
  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = a[l];
      return;
    }
    int m = (l+r)/2;
    build(l,m,2*pos+1);
    build(m+1,r,2*pos+2);
    st[pos] = st[2*pos+1] + st[2*pos+2];
  }
  void build(vi _a){
    a = _a;
    n = sz(a);
    st.assign(4*n, 0);
    build(0, n-1, 0);
  }
  void update(int l,int r,int pos,int i,int val){
    if(i < l or i > r) return;
    if(l == r){
      st[pos] = val;
      return;
    }
    int m = (l+r)/2;
    update(l, m, 2*pos+1, i, val);
    update(m+1, r, 2*pos+2, i, val);
    st[pos] = st[2*pos+1] + st[2*pos+2];
  }
  void update(int i, int val){
    update(0, n-1, 0, i, val);
  }
  ll query(int l,int r,int pos, int ql,int qr){
    if(ql > r or qr < l) return 0;
    if(ql <= l and r <= qr) return st[pos];
    int m = (l+r)/2;
    ll left = query(l, m, 2*pos+1, ql, qr);
    ll right = query(m+1, r, 2*pos+2, ql, qr);
    return left + right;
  }

  ll query(int ql,int qr){
    return query(0, n-1, 0, ql, qr);
  }
};

struct HLD{
  vi subtree_sz, parent;
  vi pos; 
  vi head; 
  vi vet; 
  int idx = 0;
  Segtree st;

  void build_hld(int u,int p = -1,int ff = 1){
    pos[u] = idx++;
    vet[pos[u]] = val[u];
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

  void build(int n, int root = 1){
    subtree_sz.resize(n+1);
    parent.resize(n+1);
    pos.resize(n+1);
    head.resize(n+1);
    vet.resize(n+1);
    build_hld(root);
    st.build(vet);
  }

  ll query_path(int u,int v){
    if(pos[u] > pos[v]) swap(u,v);

    if(head[u] == head[v])
      return st.query(pos[u], pos[v]);

    return st.query(pos[head[v]], pos[v]) + query_path(parent[head[v]], u);
  }


  void update_node(int u, int val){
    st.update(pos[u], val);
  }
};

int main(){
  fastio;

  cin >> n >> q;
  val.resize(n+1);
  for(int i=1;i<=n;i++) cin >> val[i];

  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  HLD hld;
  hld.build(n);

  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      int u, x;
      cin >> u >> x;
      hld.update_node(u, x);
    }else{
      int u;
      cin >> u;
      cout << hld.query_path(1, u) << endl;
    }
  }
  return 0;
}