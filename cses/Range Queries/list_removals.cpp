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

int n;

struct Segtree{
  vi st;
  void build(int l, int r,int pos){
    if(l == r) return;
    int m = (l+r)/2;
    build(l, m, 2*pos+1);
    build(m+1, r, 2*pos+2);
    st[pos] = st[2*pos+1] + st[2*pos+2];
  }
  Segtree(){
    st.assign(4*n, 1);
    build(0, n-1, 0);
  }
  void update(int l,int r,int pos,int i){
    if(i < l or i > r) return;
    if(l == r){
      st[pos] = 0;
      return;
    }
    int m = (l+r)/2;
    update(l,m,2*pos+1,i);
    update(m+1,r,2*pos+2,i);
    st[pos] = st[2*pos+1] + st[2*pos+2];
  }

  void update(int i){
    update(0, n-1, 0, i);
  }
  int query(int l,int r,int pos, int k){
    if(l == r) return l;
    int cnt = st[2*pos+1];
    int m = (l+r)/2;
    if(cnt >= k) return query(l, m, 2*pos+1, k);
    
    return query(m+1, r, 2*pos+2, k-cnt);
  }
  int query(int k){
    return query(0, n-1, 0, k);
  }
};

int main(){
  fastio;

  cin >> n;
  vi a(n);
  for(int i=0;i<n;i++) cin >> a[i];

  Segtree st;
  for(int i=0;i<n;i++){
    int k;
    cin >> k;
    int idx = st.query(k);
    cout << a[idx] << " ";
    st.update(idx);
  }

  cout << endl;
  
  return 0;
}