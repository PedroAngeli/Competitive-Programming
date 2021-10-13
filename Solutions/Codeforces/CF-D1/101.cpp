#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ld = long double;
using ll = long long;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
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

const int mod = 1e9 + 7;

struct Segtree{
  vector <int> st;
  int n;

  void build(int _n){
    n = _n;
    st.assign(4*n,0);
  }

  void update(int l,int r,int pos,int i,int val){
    if(r < i || l > i) return;
    if(l == r){
      st[pos] = val;
      return;
    }
    int m = (l+r)/2;
    update(l,m,2*pos+1,i,val);
    update(m+1,r,2*pos+2,i,val);
    st[pos] = st[2*pos+1] + st[2*pos+2];
    st[pos] %= mod;
  }

  void update(int i,int val){update(0, n-1, 0, i, val);}

  int query(int l,int r,int pos,int ql,int qr){
    if(qr < l || ql > r) return 0;
    if(ql <= l && r <= qr) return st[pos];
    int m = (l+r)/2;
    int sum = query(l,m,2*pos+1,ql,qr) + query(m+1,r,2*pos+2,ql,qr);
    sum %= mod;
    return sum;
  }

  int query(int ql,int qr){return query(0, n-1, 0, ql , qr);}
};

int main(){
  fastio;

  int n, m;
  vector <int> points;
  cin >> n >> m;
  points.push_back(0);
  points.push_back(n);

  vector <pair<int,int> > bus(m);

  for(int i=0;i<m;i++){
    cin >> bus[i].f >> bus[i].s;
    points.push_back(bus[i].f);
    points.push_back(bus[i].s);
  }
  sort(all(points));
  points.erase(unique(all(points)), points.end());
  map <int, int> mp;
  for(int i=0;i<points.size();i++)
    mp[points[i]] = i;

  sort(all(bus),[&](auto i,auto j){
    return i.s < j.s;
  });

  vector <int> dp(mp[n]+1, 0);
  dp[0] = 1;
  Segtree st;
  st.build(mp[n]+1);
  st.update(0, 1);
  for(int i=0;i<m;i++){
    int s = mp[bus[i].f];
    int t = mp[bus[i].s];
    dp[t] += (st.query(s, t-1));
    dp[t] %= mod;
    st.update(t, dp[t]);
  }
    
  cout << dp[mp[n]] << endl;


  return 0;
}