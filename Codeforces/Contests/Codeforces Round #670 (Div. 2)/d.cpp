#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
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

vll b,c;

bool can(ll m,int n,vll& a){
  b.resize(n);
  c.resize(n);
  c[0] = m;
  b[0] = a[0] - m;
  b[n-1] = m;
  c[n-1] = a[n-1] - b[n-1];

  if(b[0] > m || c[n-1] > m)
    return false;

  for(int i=1;i<n-1;i++){
    b[i] = b[i-1];
    ll cur_c = a[i] - b[i];

    if(cur_c <= m && cur_c <= c[i-1]){
      c[i] = cur_c;
      continue;
    }

    c[i] = c[i-1];
    ll cur_b = a[i] - c[i];

    if(cur_b <= m && cur_b >= b[i-1]){
      b[i] = cur_b;
      continue;
    }

    return false;
  }

  

  return c[n-1] <= c[n-2] && b[n-1] >= b[n-2];
}

struct Segtree{
  vll st;
  vll lazy;
  vll a;
  int len;
  void propagate(int l,int r,int pos){
    if(lazy[pos] == 0)
      return;
    st[pos] += 1LL*lazy[pos];

    if(l != r){
      lazy[2*pos+1] += lazy[pos];
      lazy[2*pos+2] += lazy[pos];
    }
    
    lazy[pos] = 0;
  }
  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = a[l];
      return; 
    }
    int m = (l+r)/2;
    build(l,m,2*pos+1);
    build(m+1,r,2*pos+2);
    st[pos] = max(st[2*pos+1],st[2*pos+2]);
  }

  void build(vll& _a){
    a = _a;
    len = sz(a);
    st.assign(4*len,INT_MIN);
    lazy.assign(4*len,0);
    build(0,len-1,0);
  }
  void add(int l,int r,int pos,int ql,int qr,ll v){
    propagate(l,r,pos);

    if(ql > r || qr < l)
      return;

    if(ql <= l && r <= qr){
      lazy[pos] += v;
      propagate(l,r,pos);
      return;
    }

    int m = (l+r)/2;
    add(l,m,2*pos+1,ql,qr,v);
    add(m+1,r,2*pos+2,ql,qr,v);

    st[pos] = max(st[2*pos+1],st[2*pos+2]);
  }
  void add(int ql,int qr,ll v){
    add(0,len-1,0,ql,qr,v);
  }
  ll get_max(int l,int r,int pos,int ql,int qr){
    propagate(l,r,pos);

    if(ql > r || qr < l)
      return INT_MIN;
    if(ql <= l && r <= qr)
      return st[pos];

    int m = (l+r)/2;
    return max(get_max(l,m,2*pos+1,ql,qr), get_max(m+1,r,2*pos+2,ql,qr));
  }
  ll get_max(int ql,int qr){
    return get_max(0,len-1,0,ql,qr);
  }
};
int main(){
  fastio;

  int t = 1;
  // cin >> t;
  while(t--){
    int n;
    cin >> n;
    vll a(n);
    for(int i=0;i<n;i++)
      cin >> a[i];

    ll l = -1e9;
    ll r = 1e9;
    ll mn = 0;

    while(l <= r){
      ll m = (l+r)/2;
      if(can(m,n,a))
        mn = m,r = m-1;
      else
        l = m+1;
    }
    can(mn,n,a);
    Segtree st_b,st_c;
    st_b.build(b);
    st_c.build(c);
    for(int i=0;i<n;i++)
      cout << b[i] << " ";
    cout << endl;
    for(int i=0;i<n;i++)
      cout << c[i] << " ";
    cout << endl;
    int q;
    cin >> q;
    cout << max(st_b.get_max(0,n-1),st_c.get_max(0,n-1)) << endl;
    while(q--){
      ll l,r,x;
      cin >> l >> r >> x;
      l--,r--;
      if(x < 0)
        st_c.add(l,r,x);
      else
        st_b.add(0,n-1,(x+1)/2),st_c.add(0,n-1,x/2);
      cout << max(st_b.get_max(0,n-1),st_c.get_max(0,n-1)) << endl;
    }
  }


  return 0;
}