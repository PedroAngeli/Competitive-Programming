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

vi a;
int n, q;

struct Node{
  int update_type; //0 no update, 1 set uptade, 2 add update
  ll val;
  Node(int update_type=0, ll val=0):
  update_type(update_type), val(val){}
};

struct Segtree{
  vll st;
  vector <Node> lazy;
  Segtree(){
    st.assign(4*n, 0);
    lazy.assign(4*n, Node());
  }

  Node merge_lazy(Node a, Node b){
    if(b.update_type == 2) return Node(a.update_type ? a.update_type : 2, a.val + b.val);
    return Node(1, b.val);
  }

  void propagate(int pos, int l, int r){
    if(lazy[pos].update_type == 0) return;

    ll tam = (r - l + 1);
    if(lazy[pos].update_type == 1) st[pos] = tam*lazy[pos].val;
    else st[pos] += tam*lazy[pos].val;

    if(l != r){
      lazy[2*pos+1] = merge_lazy(lazy[2*pos+1], lazy[pos]);
      lazy[2*pos+2] = merge_lazy(lazy[2*pos+2], lazy[pos]);
    }

    lazy[pos].update_type = lazy[pos].val = 0;
  }

  void update(int l,int r,int pos,int ql, int qr, Node x){
    propagate(pos, l, r);
    if(qr < l or ql > r) return;
    if(ql <= l and r <= qr){
      lazy[pos] = merge_lazy(lazy[pos], x);
      propagate(pos, l, r);
      return; 
    }
    int m = (l+r)/2;
    update(l, m, 2*pos+1, ql, qr, x);
    update(m+1, r, 2*pos+2, ql, qr, x);
    st[pos] = st[2*pos+1] + st[2*pos+2];
  }

  void update(int ql, int qr,Node x){
    update(0, n-1, 0, ql, qr, x);
  }

  ll query(int l,int r,int pos,int ql, int qr){
    propagate(pos, l, r);
    if(qr < l or ql > r) return 0;
    if(ql <= l and r <= qr) return st[pos];
    int m = (l+r)/2;
    return query(l, m, 2*pos+1, ql, qr) + query(m+1, r, 2*pos+2, ql, qr);
  }

  ll query(int ql, int qr){
    return query(0, n-1, 0, ql, qr);
  }
};

int main(){
  fastio;

  cin >> n >> q;
  a.resize(n);
  Segtree st;

  for(int i=0;i<n;i++){
    cin >> a[i];
    st.update(i, i, Node(2, a[i]));
  } 


  for(int i=0;i<q;i++){
    int type;
    cin >> type;
    int l, r, x;
    cin >> l >> r;
    l--, r--;
    if(type == 3) cout << st.query(l, r) << endl;
    else{
      cin >> x;
      st.update(l, r, Node(3 - type, x));
    } 
  }

  return 0;
}