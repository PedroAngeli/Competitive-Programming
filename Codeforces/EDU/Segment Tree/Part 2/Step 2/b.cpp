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

const int mod = 1e9 + 7;

struct SegTree{
  vll st;
  vll lazy;
  int sz;

  void build(int l,int r, int pos){
    if(l == r){
      st[pos] = 1;
      return;
    }

    int m = (l+r)/2;

    build(l,m,2*pos+1);
    build(m+1,r,2*pos+2);

    st[pos] = (st[2*pos+1] + st[2*pos+2]) % mod;
  }

  void build(int n){
    sz = n;
    st.assign(4*n,0);
    lazy.assign(4*n,1);
    build(0,sz-1,0);
  }

  void mult_op(ll& a, ll b){
    a = (a*b)%mod;
  }

  void propagate(int pos){ 
    mult_op(st[2*pos+1],lazy[pos]);
    mult_op(st[2*pos+2],lazy[pos]);
    mult_op(lazy[2*pos+1],lazy[pos]);
    mult_op(lazy[2*pos+2],lazy[pos]);
    lazy[pos] = 1;
  }

  void multiply(int l,int r,int pos,int ql,int qr,int v){
    if(ql > r || qr < l)
      return;
        
    if(l >= ql && r <= qr){
      mult_op(lazy[pos],v);
      mult_op(st[pos],v);
      return;
    }

    propagate(pos);

    int m = (l+r)/2;

    multiply(l,m,2*pos+1,ql,qr,v);
    multiply(m+1,r,2*pos+2,ql,qr,v);

    st[pos] = (st[2*pos+1] + st[2*pos+2])%mod;
  }

  void multiply(int ql,int qr,int v){
    multiply(0,sz-1,0,ql,qr,v);
  }

  ll get_sum(int l,int r,int pos,int ql,int qr){
    if(ql > r || qr < l)
      return 0;
    
    if(ql <= l && r <= qr)
      return st[pos];

    propagate(pos);
    
    int m = (l+r)/2;

    ll left = get_sum(l,m,2*pos+1,ql,qr);
    ll right = get_sum(m+1,r,2*pos+2,ql,qr);

    return (left + right)%mod;
  }

  ll get_sum(int ql,int qr){
    return get_sum(0,sz-1,0,ql,qr);
  }
 
};

int main(){
  fastio;

  int n,m;
  cin >> n >> m;

  SegTree st;
  st.build(n);

  while(m--){
    int type;
    cin >> type;

    if(type == 1){
      int l,r,v;
      cin >> l >> r >> v;
      r--;
      st.multiply(l,r,v);
    }else{
      int l,r;
      cin >> l >> r;
      r--;
      cout << st.get_sum(l,r) << endl;
    }
  }

  return 0;
}