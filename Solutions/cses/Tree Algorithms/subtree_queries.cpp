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
vi euler, in, out;

struct SegTree{
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
void dfs(int u=1,int p=-1){
  in[u] = sz(euler);
  euler.pb(u);
  for(int v:adj[u])
    if(v != p)
      dfs(v, u);
  out[u] = sz(euler)-1;
}

int main(){
  fastio;

  cin >> n >> q;
  val.resize(n+1);
  in.resize(n+1);
  out.resize(n+1);

  for(int i=1;i<=n;i++) cin >> val[i];

  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs();

  vi a(n);
  for(int i=0;i<n;i++)
    a[i] = val[euler[i]];

  SegTree st;
  st.build(a);

  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      int u, x;
      cin >> u >> x;
      st.update(in[u], x);
    }else{
      int u;
      cin >> u;
      cout << st.query(in[u], out[u]) << endl;
    }
  }

  return 0;
}