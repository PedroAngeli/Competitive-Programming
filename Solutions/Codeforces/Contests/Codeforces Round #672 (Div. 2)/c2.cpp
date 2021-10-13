#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
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

struct Node{
  ll min_odd, max_odd, min_even,max_even;
  Node(ll min_odd=INT_MAX,ll max_odd=INT_MIN,ll min_even=INT_MAX,ll max_even=INT_MIN):
  min_odd(min_odd), max_odd(max_odd), min_even(min_even), max_even(max_even){}
};

struct Segtree{
  vector <Node> st;
  int len;
  void build(int n){
    len = n;
    st.assign(4*n,Node());
  }
  Node merge(Node l,Node r){
    Node p;
    p.min_odd = min({l.min_odd, r.min_odd, l.min_odd - r.max_even, l.min_even + r.min_odd});
    p.max_odd = max({l.max_odd, r.max_odd, l.max_odd - r.min_even, l.max_even + r.max_odd});
    p.min_even = min({l.min_even, r.min_even, l.min_odd - r.max_odd, l.min_even + r.min_even});
    p.max_even = max({l.max_even, r.max_even, l.max_odd - r.min_odd, l.max_even + r.max_even});
    return p;
  }
  void update(int l,int r,int pos,int i,int v){
    if(i > r || i < l) return;
    if(l == r){
      st[pos] = Node(v,v,0,0);
      return;
    }
    int m = (l+r)/2;
    update(l,m,2*pos+1,i,v);
    update(m+1,r,2*pos+2,i,v);
    st[pos] = merge(st[2*pos+1],st[2*pos+2]);
  }
  void update(int i,int v){
    update(0,len-1,0,i,v);
  }
  ll max_sum(){
    return st[0].max_odd;
  }
};

int main(){
  fastio;

  int t;
  cin >> t;
  while(t--){
    int n,q;
    cin >> n >> q;
    vi a(n);
    Segtree st;
    st.build(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
      st.update(i,a[i]);
    }
    cout << st.max_sum() << endl;
    while(q--){
      int l,r;
      cin >> l >> r;
      l--,r--;
      swap(a[l],a[r]);
      st.update(l,a[l]);
      st.update(r,a[r]);
      cout << st.max_sum() << endl;
    }
  }
  
  return 0;
}