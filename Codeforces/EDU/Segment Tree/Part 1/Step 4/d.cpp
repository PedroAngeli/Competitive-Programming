#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;


typedef struct{
  vll st;
  vi original_a;
  int sz;
  int left_child(int pos){ return pos*2+1; }
  int right_child(int pos){ return pos*2+2; }

  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = (1LL << original_a[l]);
      return;
    }
    int m = (l+r)/2;
    build(l,m,left_child(pos));
    build(m+1,r,right_child(pos));
    st[pos] = st[left_child(pos)] | st[right_child(pos)];
  }

  void build(vi& a){
    original_a = a;
    sz = a.size();
    st.assign(4*sz,0);
    build(0,sz-1,0);
  }

  void update(int l,int r,int pos,int i,int v){
    if(i > r || i  < l)
      return;
    
    if(l == r){
      st[pos] &= 0;
      st[pos] |= (1LL << v);
      return;
    }
    int m = (l+r)/2;
    update(l,m,left_child(pos),i,v);
    update(m+1,r,right_child(pos),i,v);
    st[pos] = st[left_child(pos)] | st[right_child(pos)];
  }

  void update(int i,int v){
    update(0,sz-1,0,i,v);
  }

  ll different(int l,int r,int pos,int ql,int qr){
    if(ql > r || qr < l)
      return 0;
    if(l >= ql && r <= qr)
      return st[pos];
    
    int m = (l+r)/2;
    ll left = different(l,m,left_child(pos),ql,qr);
    ll right = different(m+1,r,right_child(pos),ql,qr);
    return left | right;
  }

  ll different(int l,int r){
    return different(0,sz-1,0,l,r);
  }
  
}SegTree;

int main(){
  fastio;

  int n,q;
  cin >> n >> q;
  
  vi a(n);
  for(int i=0;i<n;i++)
    cin >> a[i];

  SegTree st;
  st.build(a);

  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      int l,r;
      cin >> l >> r;
      l--,r--;
      cout << __builtin_popcountll(st.different(l,r)) << endl;
    }else{
      int i,v;
      cin >> i >> v;
      i--;
      st.update(i,v);
    }
  }
  
  
  return 0;
}