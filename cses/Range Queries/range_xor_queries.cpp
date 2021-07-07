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
  vi st, a;
  int n;
  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = a[l];
      return;
    }
    int m = (l+r)/2;
    build(l, m, 2*pos+1);
    build(m+1, r, 2*pos+2);
    st[pos] = st[2*pos+1] ^ st[2*pos+2];
  }
  void build(vi& _a){
    a = _a;
    n = sz(a);
    st.assign(4*n, 0);
    build(0, n-1, 0);
  }
  int query(int l,int r,int pos,int ql,int qr){
    if(qr < l or ql > r) return 0;
    if(ql <= l and r <= qr) return st[pos];
    int m = (l+r)/2;
    return query(l, m,2*pos+1,ql, qr) ^ query(m+1,r,2*pos+2, ql, qr);
  }
  int query(int ql,int qr){
    return query(0, n-1, 0, ql, qr);
  }
};

int main(){
  fastio;

  int n, q;
  cin >>n >> q;

  vi a(n);
  for(int i=0;i<n;i++) cin >> a[i];

  Segtree st;
  st.build(a);

  while(q--){
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << st.query(l, r) << endl;
  }
  
  return 0;
}