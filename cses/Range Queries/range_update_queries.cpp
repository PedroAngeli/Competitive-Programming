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
  vll st;
  int n;
  Segtree(int n):n(n){
    st.assign(4*n, 0);
  }
  void update(int l,int r,int pos,int ql,int qr,int val){
    if(qr < l or ql > r) return;
    if(ql <= l and r <= qr){
      st[pos] += val;
      return;
    } 
    int m = (l+r)/2;
    update(l, m,2*pos+1, ql,qr,val);
    update(m+1,r,2*pos+2, ql, qr, val);
  }
  void update(int ql,int qr, int val){
    update(0, n-1, 0, ql, qr, val);
  }
  ll query(int l,int r,int pos,int i,ll sum){
    if(l == r) return sum + st[pos];
    int m = (l+r)/2;
    if(i <= m) return query(l, m, 2*pos+1, i, sum + st[pos]);
    else return query(m+1, r, 2*pos+2, i, sum + st[pos]);
  }

  ll query(int i){
    return query(0, n-1, 0, i, 0);
  }
};

int main(){
  fastio;

  int n,q;
  cin >> n >> q;
  Segtree st(n);

  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    st.update(i,i,x);
  }

  while(q--){
    int t;
    cin >> t;
    if(t == 1){
      int a, b, u;
      cin >> a >> b >> u;
      a--,b--;
      st.update(a, b, u);
    }else{
      int k;
      cin >> k;
      k--;
      cout << st.query(k) << endl;
    }
  }
  return 0;
}