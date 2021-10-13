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
  void update(int l,int r,int pos,int i, int v){
    if(i < l or i > r) return;
    if(l == r){
      st[pos] += v;
      return;
    } 
    int m = (l+r)/2;
    update(l, m, 2*pos+1, i, v);
    update(m+1, r,2*pos+2, i,v);
    st[pos] = max(st[2*pos+1], st[2*pos+2]);
  }
  void update(int i, int v){
    update(0, n-1, 0, i, v);
  }
  int query(int l,int r,int pos,int h){
    if(st[pos] < h) return -1;
    if(l == r) return l;
    int m = (l+r)/2;
    int left = query(l, m, 2*pos+1, h);
    if(left != -1) return left;
    return query(m+1, r, 2*pos+2, h);
  }
  int query(int h){
    return query(0,n-1,0,h);
  }
};
 
int main(){
  fastio;
 
  int n, m;
  cin >>n >> m;
  Segtree st(n);
  for(int i=0;i<n;i++){
    int h;
    cin >> h;
    st.update(i, h);
  }
 
  while(m--){
    int h;
    cin >> h;
    int ans = st.query(h)+1;
    cout << ans << " ";
    if(ans == 0) continue;
    st.update(ans-1, -h);
  }
 
  cout << endl;
 
  
  return 0;
}