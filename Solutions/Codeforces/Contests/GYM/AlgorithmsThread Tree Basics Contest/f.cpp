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
vi adj[nax];
int n;
int in[nax], out[nax];
int dfs_time;

struct Segtree{
  vll st;
  Segtree(){
    st.assign(4*n, 0);
  }
  void update(int l,int r,int pos,int i, int val){
    if(i < l or i > r) return;
    if(l == r){
      st[pos] += val;
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

  ll query(int l,int r,int pos,int ql,int qr){
    if(ql > r or qr < l) return 0;
    if(ql <= l and r <= qr) return st[pos];
    int m = (l+r)/2;
    return query(l, m, 2*pos+1, ql, qr) + query(m+1,r,2*pos+2, ql, qr);
  }
  ll query(int ql,int qr){
    return query(0, n-1, 0, ql, qr);
  }
};

void dfs(int u=1, int p=-1){
  in[u] = dfs_time++;
  for(int v:adj[u])
    if(v != p)
      dfs(v, u);
  out[u] = dfs_time - 1;
}

void match(ll& s, ll& p){
  ll prev_s = s;
  s = max(0LL, s - p);
  p = max(0LL, p - prev_s);
}

int main(){
  fastio;

  int t;
  cin >> t;

  while(t--){
    int q;
    cin >> n >> q;

    for(int i=1;i<=n;i++) adj[i].clear();
    dfs_time = 0;

    for(int i=0;i<n-1;i++){
      int u,v;
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }

    dfs();
    Segtree seeds, pots;  

    while(q--){
      int u, v, x;
      cin >> u >> v >> x;
      if(x){
        seeds.update(in[u], x);
        pots.update(in[v], x);
      }else{
        if(in[u] > in[v]) swap(u, v);

        ll s2 = seeds.query(in[v], out[v]);
        ll p2 = pots.query(in[v], out[v]);
        ll ts = seeds.query(0, n-1);
        ll tp = pots.query(0, n-1);
        ll s1 = ts - s2;
        ll p1 = tp - p2;
        match(s1, p1);
        match(s2, p2);

        cout << min(s1, p2) + min(s2,p1) << endl;
      }
    }
  }

  return 0;
}