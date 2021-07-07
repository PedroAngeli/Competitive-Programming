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

struct SegTree{
  vll st;
  vll lazy;
  int sz;

  void build(int n){
    sz = n;
    st.assign(4*n,0);
    lazy.assign(4*n,0);
  }

  void propagate(int pos){ 
    st[2*pos+1] += lazy[pos];
    st[2*pos+2] += lazy[pos];
    lazy[2*pos+1] += lazy[pos];
    lazy[2*pos+2] += lazy[pos];
    lazy[pos] = 0;
  }

  void add(int l,int r,int pos,int ql,int qr,int v){
    if(ql > r || qr < l)
      return;
        
    if(l >= ql && r <= qr){
      lazy[pos] += v;
      st[pos] += v;
      return;
    }

    propagate(pos);

    int m = (l+r)/2;

    add(l,m,2*pos+1,ql,qr,v);
    add(m+1,r,2*pos+2,ql,qr,v);

    st[pos] = min(st[2*pos+1],st[2*pos+2]);
  }

  void add(int ql,int qr,int v){
    add(0,sz-1,0,ql,qr,v);
  }

  ll get_min(int l,int r,int pos,int ql,int qr){
    if(ql > r || qr < l)
      return LLONG_MAX;
    
    if(ql <= l && r <= qr)
      return st[pos];

    propagate(pos);
    
    int m = (l+r)/2;

    ll left = get_min(l,m,2*pos+1,ql,qr);
    ll right = get_min(m+1,r,2*pos+2,ql,qr);

    return min(left, right);
  }

  ll get_min(int ql,int qr){
    return get_min(0,sz-1,0,ql,qr);
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
      st.add(l,r,v);
    }else{
      int l,r;
      cin >> l >> r;
      r--;
      cout << st.get_min(l,r) << endl;
    }
  }

  return 0;
}