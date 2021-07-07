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
vi a;

struct Segtree{
  vi st;
  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = l;
      return;
    }
    int m = (l+r)/2;
    build(l, m, 2*pos+1);
    build(m+1, r,2*pos+2);
    int left = st[2*pos+1];
    int right = st[2*pos+2];
    st[pos] = (a[left] <= a[right]) ? left : right;
  }
  Segtree(){
    st.assign(4*n, -1);
    build(0, n-1, 0);
  }
  int query(int l,int r,int pos,int ql,int qr){
    if(ql > r or qr < l) return -1;
    if(ql <= l and r <= qr) return st[pos];
    int m = (l+r)/2;
    int left = query(l, m, 2*pos+1, ql, qr);
    int right = query(m+1, r, 2*pos+2, ql, qr);
    if(left == -1) return right;
    if(right == -1) return left;
    return (a[left] <= a[right]) ? left : right;
  }
  int query(int ql,int qr){
    return query(0, n-1, 0, ql,qr);
  }
};

int main(){
  fastio;

  int t;
  cin >> t;

  while(t--){
    cin >> n;
    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];

    Segtree st;

    vi pref(n);
    for(int i=0;i<n;i++){
      pref[i] = a[i];
      if(i > 0) pref[i] = max(pref[i], pref[i-1]);
    }

    int mx = 0;
    bool can = false;

    for(int i=n-1;i>=0;i--){
      mx = max(mx, a[i]);
      int l = lb(pref.begin(), pref.begin() + i, mx) - pref.begin();
      if(a[l] != mx) continue;
      int r = ub(pref.begin(), pref.begin() + i, mx) - pref.begin() - 1;
      
      int idx = -1;
      int last = -1;
      l++, r++;
      while(l <= r){
        int m = (l+r)/2;
        int ret = st.query(m, i-1);
        if(ret == -1 or a[ret] > mx) r = m-1;
        else l = m+1, idx = m, last = ret;
      }
      if(last == -1 or a[last] != mx) continue;
      can = true;
      cout << "YES" << endl;
      int x = idx, y = n-(n-i + idx), z = n-i;
      cout << x << " " << y << " " << z << endl;
      break;
    }

    if(!can) cout << "NO" << endl;
  }
  
  return 0;
}