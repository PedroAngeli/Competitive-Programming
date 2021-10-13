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

const int nax = 2e5;
int n, q;
vi a;

struct Segtree{
  vll st;
  vll lazy_1, lazy_2;
  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = a[l];
      return;
    }
    int m = (l+r)/2;
    build(l, m, 2*pos+1);
    build(m+1, r, 2*pos+2);
    st[pos] = st[2*pos+1] + st[2*pos+2];
  }
  Segtree(){
    st.assign(4*n, 0);
    lazy_1.assign(4*n, 0);
    lazy_2.assign(4*n, 0);
    build(0, n-1, 0);
  }
  ll pa(ll a1, ll an){
    return ((a1 + an)*(an - a1 + 1))/2;
  }
  void propagate(ll l,ll r,int pos){
    st[pos] += lazy_1[pos]*(r-l+1) + lazy_2[pos]*pa(1, (r-l+1));
    
    int m = (l+r)/2;
    if(l != r){
      lazy_1[2*pos+1] += lazy_1[pos];
      lazy_2[2*pos+1] += lazy_2[pos];
      lazy_1[2*pos+2] += (lazy_1[pos] + lazy_2[pos]*(m+1 - l));
      lazy_2[2*pos+2] += lazy_2[pos];
    }
    lazy_1[pos] = 0;
    lazy_2[pos] = 0;
  }

  void update(int l,int r,int pos,int ql, int qr){
    propagate(l, r, pos);
    if(ql > r or qr < l) return;
    if(ql <= l and r <= qr){
      lazy_1[pos] += (l-ql);
      lazy_2[pos]++;
      propagate(l, r, pos);
      return;
    }
    int m = (l+r)/2;
    update(l, m, 2*pos+1, ql, qr);
    update(m+1, r, 2*pos+2, ql, qr);
    st[pos] = st[2*pos+1] + st[2*pos+2];
  }

  void update(int ql,int qr){
    update(0, n-1, 0, ql, qr);
  }
  
  ll query(int l,int r,int pos,int ql,int qr){
    propagate(l, r, pos);
    if(ql > r or qr < l) return 0;
    if(ql <= l and r <= qr) return st[pos];
    int m = (l+r)/2;
    return query(l, m, 2*pos+1, ql, qr) + query(m+1, r, 2*pos+2, ql, qr);
  }

  ll query(int ql,int qr){
    return query(0, n-1, 0, ql, qr);
  }
};

int main(){
  fastio;

  cin >> n >> q;
  a.resize(n);
  for(int i=0;i<n;i++)
    cin >> a[i];

  Segtree st;

  while(q--){
    int t, a, b;
    cin >> t >> a >> b;
    a--, b--;
    if(t == 1) st.update(a, b);
    else cout << st.query(a, b) << endl;
  }

  return 0;
}