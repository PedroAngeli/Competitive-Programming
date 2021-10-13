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


struct Segtree{
  vll st;
  vll lazy;
  vll a;
  int len;
  void propagate(int l,int r,int pos){
    st[pos] += lazy[pos];
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

    st[pos] = min(st[2*pos+1],st[2*pos+2]);
  }
  void build(vll& _a){
    a = _a;
    len = sz(a);
    st.assign(4*len,LLONG_MAX);
    lazy.assign(4*len,0);
    build(0,len-1,0);
  }
  void add(int l,int r,int pos,int ql,int qr,int v){
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
    st[pos] = min(st[2*pos+1],st[2*pos+2]);
  }

  void add(int ql,int qr,int v){
    add(0,len-1,0,ql,qr,v);
  }

  ll rmq(int l,int r,int pos,int ql,int qr){
    propagate(l,r,pos);

    if(ql > r || qr < l)
      return LLONG_MAX;

    if(ql <= l && r <= qr)
      return st[pos];

    int m = (l+r)/2;

    return min(rmq(l,m,2*pos+1,ql,qr), rmq(m+1,r,2*pos+2,ql,qr));
  }

  ll rmq(int ql,int qr){
    return rmq(0,len-1,0,ql,qr);
  }
};

int main(){
  fastio;

  int n;
  cin >> n;
  vll a(n);
  for(int i=0;i<n;i++)
    cin >> a[i];
  Segtree st;
  st.build(a);

  int q;
  cin >> q;
    string line;
    getline(cin,line);

  while(q--){
    getline(cin,line);
    stringstream ss(line);
    vi vals;
    int val;
    while(ss >> val)
      vals.pb(val);
      
    int l = vals[0],r = vals[1];
    if(sz(vals) == 2){
      ll ans;
      if(r < l)
        ans = min(st.rmq(l,n-1),st.rmq(0,r));
      else
        ans = st.rmq(l,r);
      cout << ans << endl;
    }
    else{
      int v = vals[2];
      if(r < l)
        st.add(l,n-1,v), st.add(0,r,v);
      else
        st.add(l,r,v);
    }
  }

  return 0;
}