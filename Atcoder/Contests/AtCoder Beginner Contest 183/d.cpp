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

struct Segtree{
  vll st, lazy;
  int n;

  void build(int _n){
    n = _n;
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


int main(){
  fastio;

  int n, w;

  cin >> n >> w;

  Segtree st;
  st.build(n+10);

  int mx = 0;

  for(int i=0;i<n;i++){
    int l, r, p;
    cin >> l >> r >> p;
    r--;
    st.update(l, r, p);
    mx = max(mx, r);
  }

  bool can = true;

  for(int i=0;i<=mx;i++)
    can = (can and (st.query(i, i) <= w));
  
  cout << (can ? "Yes" : "No") << endl;
  return 0;
}