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
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

const int mod = 998244353;

struct Segtree{
  vll st;
  int len;
  void build(int n){
    len = n;
    st.assign(4*n,0);
  }

  void update(int l,int r,int pos,int i,ll v){
    if(i < l || i > r)
      return;
    if(l == r){
      st[pos] = v;
      return;
    }
    int m = (l+r)/2;
    update(l,m,2*pos+1,i,v);
    update(m+1,r,2*pos+2,i,v);

    st[pos] = st[2*pos+1] + st[2*pos+2];
  }
  void update(int i,ll v){
    update(0,len-1,0,i,v);
  }
  ll get_sum(int l,int r,int pos,int ql,int qr){
    if(ql > r || qr < l)
      return 0;
    if(ql <= l && r <= qr)
      return st[pos];
    
    int m = (l+r)/2;

    return get_sum(l,m,2*pos+1,ql,qr) + get_sum(m+1,r,2*pos+2,ql,qr);
  }
  ll get_sum(int ql,int qr){
    return get_sum(0,len-1,0,ql,qr);
  }
  
};

int main(){
  fastio;

  int n,k;
  cin >> n >> k;

  vpii segs(k);

  for(int i=0;i<k;i++)
    cin >> segs[i].f >> segs[i].s;
  
  Segtree st;
  st.build(n+1);
  vll dp(n+1,0);
  dp[1] = 1;
  st.update(1,1);

  for(int i=2;i<=n;i++){
    for(int j=0;j<k;j++){
      int l = segs[j].f;
      int r = segs[j].s;
      if(i-l < 1)
        continue;
      dp[i] += st.get_sum(max(1,i-r),i-l); 
      dp[i] %= mod;
    }
    st.update(i,dp[i]);
  }

  cout << dp[n] << endl;
  return 0;
}