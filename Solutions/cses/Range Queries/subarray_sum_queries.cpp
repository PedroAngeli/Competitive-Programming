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
int n, m;

struct Node{
  ll pref, suf, max_sub, sum;
  Node(ll pref=0, ll suf=0,ll max_sub=0, ll sum=0):
  pref(pref), suf(suf), max_sub(max_sub), sum(sum){}
};

struct Segtree{
  vector <Node> st;
  Segtree(){
    st.assign(4*n, Node());
  }
  void update(int l,int r,int pos,int i, int val){
    if(i < l or i > r) return;
    if(l == r){
      st[pos] = Node(val, val, val, val);
      return;
    }
    int m = (l+r)/2;
    update(l, m, 2*pos+1, i, val);
    update(m+1, r, 2*pos+2, i, val);
    ll sum = st[2*pos+1].sum + st[2*pos+2].sum;
    ll pref = max(st[2*pos+1].pref, st[2*pos+1].sum + st[2*pos+2].pref);
    ll suf = max(st[2*pos+2].suf, st[2*pos+2].sum + st[2*pos+1].suf);
    ll max_sub = max({st[2*pos+1].max_sub, st[2*pos+2].max_sub, st[2*pos+1].suf + st[2*pos+2].pref}); 
    st[pos] = Node(pref, suf, max_sub, sum);
  }
  void update(int i, int val){
    update(0, n-1, 0, i, val);
  }
  ll query(){
    return st[0].max_sub;
  }
};

int main(){
  fastio;

  cin >> n >> m;
  
  Segtree st;

  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    st.update(i, x);
  }

  while(m--){
    int k, x;
    cin >> k >> x;
    k--;
    st.update(k, x);
    cout << max(0LL, st.query()) << endl;
  }
  return 0;
}