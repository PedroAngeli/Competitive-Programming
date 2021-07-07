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
int in[nax], out[nax];
vi adj[nax];
vi euler;
int n;

namespace Segtree{
  vll st, lazy;

  void build(){
    st.assign(4*n,0);
    lazy.assign(4*n,0);
  }

  void propagate(int l,int r,int pos){
    if(lazy[pos] == 0) return;
    st[pos] += lazy[pos] * (r - l + 1);
    if(l != r){
      lazy[2*pos+1] += lazy[pos];
      lazy[2*pos+2] += lazy[pos];
    }
    lazy[pos] = 0;
  }

  void update(int l,int r,int pos,int ql,int qr,int val){
    propagate(l,r,pos);
    if(qr < l || ql > r) return;
    if(ql <= l && r <= qr){
      lazy[pos] += val;
      propagate(l,r,pos);
      return;
    }
    int m = (l+r)/2;
    update(l,m,2*pos+1,ql,qr,val);
    update(m+1,r,2*pos+2,ql,qr,val);
    st[pos] = st[2*pos+1] + st[2*pos+2];
  }

  void update(int ql,int qr,int val){update(0, n-1, 0, ql, qr, val);}

  ll query(int l,int r,int pos,int ql,int qr){
    propagate(l,r,pos);
    if(qr < l || ql > r) return 0;
    if(ql <= l && r <= qr) return st[pos];
    int m = (l+r)/2;
    return query(l,m,2*pos+1,ql,qr) + query(m+1,r,2*pos+2,ql,qr);
  }

  ll query(int ql,int qr){return query(0, n-1, 0, ql , qr);}
};

void dfs(int u=1,int p=-1){
  in[u] = sz(euler);
  euler.pb(u);
  for(int v:adj[u])
    if(v != p)
      dfs(v, u);
  out[u] = sz(euler) - 1;
}

int main(){
  fastio;

  cin >> n;
  vpii edges;

  for(int i=0;i<n-1;i++){
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    edges.pb({u, v});
  } 

  Segtree :: build();

  dfs(); 

  int q;
  cin >> q;
  while(q--){
    int t, e, x;
    cin >> t >> e >> x;
    e--;
    int u = edges[e].f, v = edges[e].s;
    if(t == 1){
      if(in[u] < in[v]){
        Segtree :: update(0, sz(euler)-1, x);
        Segtree :: update(in[v], out[v], -x);
      }else{
        Segtree :: update(in[u], out[u], x);
      }
    }else{
      if(in[u] > in[v]){
        Segtree :: update(0, sz(euler)-1, x);
        Segtree :: update(in[u], out[u], -x);
      }else{
        Segtree :: update(in[v], out[v], x);
      }
    }
  }

  for(int i=1;i<=n;i++)
    cout << Segtree :: query(in[i], in[i]) << endl;
  
  return 0;
}